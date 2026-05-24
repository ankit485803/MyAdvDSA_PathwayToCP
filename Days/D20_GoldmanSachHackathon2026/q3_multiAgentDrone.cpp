

/*

https://www.hackerrank.com/contests/goldman-sachs-india-hackathon-2026-cs/challenges/dronedelivery




*/


// Start of HEAD
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <json/json.h>  // jsoncpp (provided on HackerRank)

using namespace std;

int main() {
    // Read all input from stdin
    string input_str((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    Json::Value input_data;
    Json::CharReaderBuilder rb;
    string errs;
    istringstream ss(input_str);
    Json::parseFromStream(rb, ss, &input_data, &errs);

    double mapW = input_data["map_size"][0].asDouble();
    double mapH = input_data["map_size"][1].asDouble();
    double warehouseX = mapW / 2.0, warehouseY = mapH / 2.0;
    Json::Value drones = input_data["drones"];
    Json::Value deliveries = input_data["deliveries"];
    Json::Value no_fly_zones = input_data.get("no_fly_zones", Json::Value(Json::arrayValue));
    Json::Value charging_stations = input_data.get("charging_stations", Json::Value(Json::arrayValue));
// End of HEAD

// Start of BODY
    /*
     * Schedule drone deliveries to maximize on-time deliveries
     * while minimizing energy and makespan.
     *
     * Input:
     *   warehouse: [x, y] - center of map, pickup/return location
     *   drones: array of {"id": str, "max_payload": double}
     *   deliveries: array of {"id": str, "x": double, "y": double, "weight": double, "deadline": double}
     *   no_fly_zones: array of {"shape": "circle"|"rectangle", "center"/"corners", "radius", "T_start", "T_end"}
     *   charging_stations: array of {"x": double, "y": double}
     *
     * Output:
     *   JSON: {"flight_manifest": [drone_entries]}
     *   Each drone_entry: {"drone_id": str, "path": [steps]}
     *   Each step: {"x": double, "y": double, "t": double, "action": str, ...}
     *   Actions: PICKUP (+delivery_ids), DELIVER (+delivery_id), RETURN, CHARGE, CHARGE_COMPLETE, WAIT, WAYPOINT
     *
     * Scoring:
     *   score = (on_time_deliveries * 100) - (total_energy * 0.1) - (makespan * 0.05)
     *   energy per leg = distance * (1 + current_payload_weight)
     *   Battery capacity = 500, recharges on RETURN to warehouse
     */

    Json::Value flight_manifest(Json::arrayValue);

    // TODO: Implement your solution here

// End of BODY

// Start of TAIL
    Json::Value output;
    output["flight_manifest"] = flight_manifest;
    Json::StreamWriterBuilder wb;
    wb["indentation"] = "";
    cout << Json::writeString(wb, output) << endl;
    return 0;
}
// End of TAIL





// Start of HEAD
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <json/json.h>  // jsoncpp (provided on HackerRank)

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double distanceTo(const Point& other) const {
        return hypot(x - other.x, y - other.y);
    }
};

struct NFZ {
    string shape;
    Point center;
    double radius;
    double x1, y1, x2, y2; // for rectangle
    double T_start, T_end;
    
    bool isPointBlocked(double t, const Point& p) const {
        if (t < T_start || t > T_end) return false;
        
        if (shape == "circle") {
            double dist = center.distanceTo(p);
            return dist <= radius;
        } else if (shape == "rectangle") {
            return (p.x >= min(x1, x2) && p.x <= max(x1, x2) &&
                    p.y >= min(y1, y2) && p.y <= max(y1, y2));
        }
        return false;
    }
    
    bool isSegmentBlocked(double t_start, const Point& p1, const Point& p2, double speed = 1.0) const {
        double distance = p1.distanceTo(p2);
        if (distance < 1e-9) return isPointBlocked(t_start, p1);
        
        // Check multiple points along the segment
        int steps = max(10, (int)(distance * 10));
        for (int i = 0; i <= steps; i++) {
            double ratio = (double)i / steps;
            Point p(p1.x + ratio * (p2.x - p1.x), p1.y + ratio * (p2.y - p1.y));
            double t = t_start + ratio * distance / speed;
            if (isPointBlocked(t, p)) return true;
        }
        return false;
    }
};

struct Delivery {
    string id;
    Point pos;
    double weight;
    double deadline;
};

struct Drone {
    string id;
    double max_payload;
    Point pos;
    double battery;
    double time;
    vector<double> payload_weights;
    vector<string> delivery_ids;
    Json::Value path;
    
    Drone(const string& i, double payload, const Point& start) 
        : id(i), max_payload(payload), pos(start), battery(500.0), time(0.0) {}
    
    bool canCarry(double weight) const {
        double total = 0;
        for (double w : payload_weights) total += w;
        return total + weight <= max_payload;
    }
    
    void addPackage(double weight, const string& delivery_id) {
        payload_weights.push_back(weight);
        delivery_ids.push_back(delivery_id);
    }
    
    void removePackage(const string& delivery_id) {
        for (size_t i = 0; i < delivery_ids.size(); i++) {
            if (delivery_ids[i] == delivery_id) {
                payload_weights.erase(payload_weights.begin() + i);
                delivery_ids.erase(delivery_ids.begin() + i);
                return;
            }
        }
    }
    
    double getCurrentPayload() const {
        double total = 0;
        for (double w : payload_weights) total += w;
        return total;
    }
    
    bool moveTo(const Point& target, double& energy_cost, double& travel_time, 
                const vector<NFZ>& nfzs, double start_time) {
        double distance = pos.distanceTo(target);
        travel_time = distance;
        
        // Check NFZs along the path
        for (const auto& nfz : nfzs) {
            if (nfz.isSegmentBlocked(start_time, pos, target, 1.0)) {
                return false;
            }
        }
        
        double current_payload = getCurrentPayload();
        energy_cost = distance * (1.0 + current_payload);
        
        if (battery - energy_cost < -1e-9) return false;
        
        return true;
    }
    
    void applyMove(const Point& target, double energy_cost, double travel_time) {
        battery -= energy_cost;
        time += travel_time;
        pos = target;
    }
};

// Helper function to check if a charging station exists at a point
bool isChargingStation(const Point& p, const Json::Value& stations) {
    for (const auto& station : stations) {
        if (fabs(station["x"].asDouble() - p.x) < 1e-6 &&
            fabs(station["y"].asDouble() - p.y) < 1e-6) {
            return true;
        }
    }
    return false;
}
// End of HEAD

// Start of BODY
int main() {
    // Read all input from stdin
    string input_str((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    Json::Value input_data;
    Json::CharReaderBuilder rb;
    string errs;
    istringstream ss(input_str);
    Json::parseFromStream(rb, ss, &input_data, &errs);

    double mapW = input_data["map_size"][0].asDouble();
    double mapH = input_data["map_size"][1].asDouble();
    double warehouseX = mapW / 2.0, warehouseY = mapH / 2.0;
    Point warehouse(warehouseX, warehouseY);
    
    Json::Value drones_json = input_data["drones"];
    Json::Value deliveries_json = input_data["deliveries"];
    Json::Value no_fly_zones_json = input_data.get("no_fly_zones", Json::Value(Json::arrayValue));
    Json::Value charging_stations_json = input_data.get("charging_stations", Json::Value(Json::arrayValue));
    
    // Parse deliveries
    vector<Delivery> deliveries;
    map<string, Delivery> delivery_map;
    for (const auto& d : deliveries_json) {
        Delivery del;
        del.id = d["id"].asString();
        del.pos.x = d["x"].asDouble();
        del.pos.y = d["y"].asDouble();
        del.weight = d["weight"].asDouble();
        del.deadline = d["deadline"].asDouble();
        deliveries.push_back(del);
        delivery_map[del.id] = del;
    }
    
    // Parse NFZs
    vector<NFZ> nfzs;
    for (const auto& nfz_json : no_fly_zones_json) {
        NFZ nfz;
        nfz.shape = nfz_json["shape"].asString();
        nfz.T_start = nfz_json["T_start"].asDouble();
        nfz.T_end = nfz_json["T_end"].asDouble();
        
        if (nfz.shape == "circle") {
            nfz.center.x = nfz_json["center"][0].asDouble();
            nfz.center.y = nfz_json["center"][1].asDouble();
            nfz.radius = nfz_json["radius"].asDouble();
        } else if (nfz.shape == "rectangle") {
            nfz.x1 = nfz_json["corners"][0][0].asDouble();
            nfz.y1 = nfz_json["corners"][0][1].asDouble();
            nfz.x2 = nfz_json["corners"][1][0].asDouble();
            nfz.y2 = nfz_json["corners"][1][1].asDouble();
        }
        nfzs.push_back(nfz);
    }
    
    Json::Value flight_manifest(Json::arrayValue);
    
    // Simple greedy approach: one drone does all deliveries in optimal order
    for (const auto& drone_json : drones_json) {
        Drone drone(drone_json["id"].asString(), drone_json["max_payload"].asDouble(), warehouse);
        
        // Sort deliveries by deadline (earliest first) and by distance
        vector<Delivery> remaining = deliveries;
        
        // Create path steps
        Json::Value path(Json::arrayValue);
        
        // PICKUP step at warehouse
        Json::Value pickup_step;
        pickup_step["x"] = warehouse.x;
        pickup_step["y"] = warehouse.y;
        pickup_step["t"] = 0.0;
        pickup_step["action"] = "PICKUP";
        
        Json::Value delivery_ids_array(Json::arrayValue);
        for (const auto& del : remaining) {
            delivery_ids_array.append(del.id);
            drone.addPackage(del.weight, del.id);
        }
        pickup_step["delivery_ids"] = delivery_ids_array;
        path.append(pickup_step);
        
        // Deliver each package
        double current_time = 0.0;
        Point current_pos = warehouse;
        double current_battery = 500.0;
        vector<pair<string, double>> payload_weights;
        
        // Reset drone state for simulation
        for (const auto& del : remaining) {
            payload_weights.push_back({del.id, del.weight});
        }
        
        vector<Delivery> delivery_order = remaining;
        
        // Simple delivery order: sort by distance from warehouse or deadline
        sort(delivery_order.begin(), delivery_order.end(), [&](const Delivery& a, const Delivery& b) {
            double dist_a = warehouse.distanceTo(a.pos);
            double dist_b = warehouse.distanceTo(b.pos);
            return dist_a < dist_b;
        });
        
        // Deliver each package
        for (const auto& del : delivery_order) {
            // Calculate energy and travel time
            double distance = current_pos.distanceTo(del.pos);
            double current_payload = 0;
            for (const auto& p : payload_weights) current_payload += p.second;
            
            double energy_cost = distance * (1.0 + current_payload);
            double travel_time = distance;
            
            // Check if we have enough battery
            if (current_battery - energy_cost < -1e-9) {
                // Need to charge or return to warehouse
                // For simplicity, return to warehouse first
                double dist_to_warehouse = current_pos.distanceTo(warehouse);
                double energy_to_warehouse = dist_to_warehouse * (1.0 + current_payload);
                
                if (current_battery >= energy_to_warehouse) {
                    // Return to warehouse
                    Json::Value return_step;
                    return_step["x"] = warehouse.x;
                    return_step["y"] = warehouse.y;
                    return_step["t"] = current_time + dist_to_warehouse;
                    return_step["action"] = "RETURN";
                    path.append(return_step);
                    
                    current_time += dist_to_warehouse;
                    current_battery = 500.0; // Fully recharged
                    current_pos = warehouse;
                    
                    // Recalculate energy for delivery
                    distance = current_pos.distanceTo(del.pos);
                    energy_cost = distance * (1.0 + current_payload);
                    travel_time = distance;
                }
            }
            
            // Check if path is blocked by NFZ
            bool path_blocked = false;
            for (const auto& nfz : nfzs) {
                if (nfz.isSegmentBlocked(current_time, current_pos, del.pos, 1.0)) {
                    path_blocked = true;
                    break;
                }
            }
            
            if (path_blocked) {
                // Try to wait or find alternative path
                // For now, just wait for NFZ to expire
                double max_wait = 0;
                for (const auto& nfz : nfzs) {
                    if (nfz.isSegmentBlocked(current_time, current_pos, del.pos, 1.0)) {
                        double wait_time = max(0.0, nfz.T_end - current_time);
                        max_wait = max(max_wait, wait_time);
                    }
                }
                
                // Add WAIT step
                if (max_wait > 0) {
                    Json::Value wait_step;
                    wait_step["x"] = current_pos.x;
                    wait_step["y"] = current_pos.y;
                    wait_step["t"] = current_time + max_wait;
                    wait_step["action"] = "WAIT";
                    path.append(wait_step);
                    current_time += max_wait;
                }
            }
            
            // Perform delivery
            if (current_battery >= energy_cost && current_time + travel_time <= del.deadline) {
                Json::Value deliver_step;
                deliver_step["x"] = del.pos.x;
                deliver_step["y"] = del.pos.y;
                deliver_step["t"] = current_time + travel_time;
                deliver_step["action"] = "DELIVER";
                deliver_step["delivery_id"] = del.id;
                path.append(deliver_step);
                
                current_time += travel_time;
                current_battery -= energy_cost;
                current_pos = del.pos;
                
                // Remove delivered package from payload
                for (auto it = payload_weights.begin(); it != payload_weights.end(); ++it) {
                    if (it->first == del.id) {
                        payload_weights.erase(it);
                        break;
                    }
                }
            }
        }
        
        // Return to warehouse
        if (current_pos.distanceTo(warehouse) > 1e-6) {
            double distance = current_pos.distanceTo(warehouse);
            double current_payload = 0;
            for (const auto& p : payload_weights) current_payload += p.second;
            double energy_cost = distance * (1.0 + current_payload);
            
            if (current_battery >= energy_cost) {
                Json::Value return_step;
                return_step["x"] = warehouse.x;
                return_step["y"] = warehouse.y;
                return_step["t"] = current_time + distance;
                return_step["action"] = "RETURN";
                path.append(return_step);
            }
        }
        
        // Create drone entry
        Json::Value drone_entry;
        drone_entry["drone_id"] = drone.id;
        drone_entry["path"] = path;
        flight_manifest.append(drone_entry);
        
        // Only use first drone
        break;
    }
    
    // End of BODY
    
    // Start of TAIL
    Json::Value output;
    output["flight_manifest"] = flight_manifest;
    Json::StreamWriterBuilder wb;
    wb["indentation"] = "";
    cout << Json::writeString(wb, output) << endl;
    return 0;
}
// End of TAIL