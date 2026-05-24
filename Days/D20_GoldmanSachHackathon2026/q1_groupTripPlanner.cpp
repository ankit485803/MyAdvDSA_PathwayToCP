

/*

https://www.hackerrank.com/contests/goldman-sachs-india-hackathon-2026-cs/challenges/group-trip-planner


which topics from dsa is this prob and which concepts used here
It is actually closer to a CP (Competitive Programming) simulation + optimization problem.
Topic:
Bitmasking
Power Set Generation
Subset Enumeration
2. Greedy Tie Breaking

After generating feasible subsets:

You choose:

Maximum satisfaction
Minimum cost
Lexicographically smallest IDs



*/



#include <bits/stdc++.h>
using namespace std;

struct User {
    string name;
    int budget;
    int energy;
    set<string> tags;
    bool active = true;
};

struct Activity {
    int id;
    string name;
    int cost;
    int duration;
    int energy;
    string tag;
};

struct Input {
    int N, D, H;
    vector<User> users;
    map<int, Activity> activities;     // ordered by id
    vector<string> events;             // verbatim event lines
};

static Input readInput() {
    Input in;
    cin >> in.N >> in.D >> in.H;
    in.users.resize(in.N);
    for (int i = 0; i < in.N; i++) {
        int k;
        cin >> in.users[i].name >> in.users[i].budget >> in.users[i].energy >> k;
        for (int j = 0; j < k; j++) {
            string t; cin >> t;
            in.users[i].tags.insert(t);
        }
        in.users[i].active = true;
    }
    int A; cin >> A;
    for (int i = 0; i < A; i++) {
        Activity a;
        cin >> a.id >> a.name >> a.cost >> a.duration >> a.energy >> a.tag;
        in.activities[a.id] = a;
    }
    int E; cin >> E;
    cin.ignore();
    for (int i = 0; i < E; i++) {
        string line;
        getline(cin, line);
        // trim
        while (!line.empty() && (line.back() == '\r' || line.back() == ' ')) line.pop_back();
        in.events.push_back(line);
    }
    return in;
}

/** Format a single day line exactly per spec. Use REST if ids is empty. */
static string formatDay(int day, vector<int> ids, int cost, int sat) {
    if (ids.empty()) {
        return "Day " + to_string(day) + ": REST | cost=0 satisfaction=0";
    }
    sort(ids.begin(), ids.end());
    string s = "Day " + to_string(day) + ": ";
    for (size_t i = 0; i < ids.size(); i++) {
        if (i) s += ' ';
        s += to_string(ids[i]);
    }
    s += " | cost=" + to_string(cost) + " satisfaction=" + to_string(sat);
    return s;
}

// =========================================================================
// YOUR CODE GOES HERE.
//
// Implement solve(const Input& in) and return the FULL output string
// (including the trailing newline) that the judge will diff against
// the expected output.
//
// Helpers available from the Head section:
//   - formatDay(day, ids, cost, sat)  -> properly formatted "Day X: ..." line
//   - in.users        : vector<User>           ({name, budget, energy, tags, active})
//   - in.activities   : map<int,Activity>      ({id, name, cost, duration, energy, tag})
//   - in.events       : vector<string>         verbatim event lines, e.g.
//                       "DROP 2 Bob", "WEATHER 3 NATURE",
//                       "FATIGUE 2 Alice 5", "BUDGET 4 Alice 20"
// =========================================================================
static string solve(Input in) {
    string out;
    out += "=== PLAN ===\n";

    // TODO 1: build the initial D-day plan.
    //   for (int day = 1; day <= in.D; day++) {
    //       out += formatDay(day, chosenIds, totalCost, satisfaction) + "\n";
    //   }

    // TODO 2: process events in order. For each event i (1-indexed):
    //   - append "=== EVENT i: <event line verbatim> ===\n"
    //   - mutate state (DROP / WEATHER / FATIGUE / BUDGET)
    //   - re-plan days [eventDay .. D], preserving days [1 .. eventDay-1]

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Input in = readInput();
    cout << solve(in);
    return 0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Input in = readInput();

    // =========================
    // YOUR LOGIC STARTS HERE
    // =========================

    // STEP 1:
    // Create initial trip plan for D days

    // STEP 2:
    // For each day:
    //   - find all valid subsets of activities
    //   - apply constraints:
    //         cost <= min budget
    //         energy <= min energy
    //         duration <= H
    //   - maximize satisfaction
    //   - tie break using:
    //         lower cost
    //         lexicographically smaller ids

    // STEP 3:
    // Store chosen activities
    // so they are not reused later

    // STEP 4:
    // Print initial plan

    // STEP 5:
    // Process each event one by one
    // WEATHER / DROP / FATIGUE / BUDGET

    // STEP 6:
    // After every event:
    //   - update system state
    //   - replan remaining days only

    // =========================
    // YOUR LOGIC ENDS HERE
    // =========================

    return 0;
}7




static string solve(Input in) {
    string out;
    out += "=== PLAN ===\n";
    
    // Track weather blocks from events (day, blocked_tag)
    vector<pair<int, string>> weatherBlocks;
    
    // Store plans for each day (1-indexed, index 0 = day 1)
    vector<PlanResult> dayPlans(in.D);
    
    // TODO: Initial planning for days 1 to D
    // Plan days 1..in.D and store results in dayPlans
    
    // Output initial plan
    for (int day = 1; day <= in.D; day++) {
        out += formatDay(day, dayPlans[day-1].ids, dayPlans[day-1].cost, dayPlans[day-1].satisfaction) + "\n";
    }
    
    // Process events in order
    for (size_t eventIdx = 0; eventIdx < in.events.size(); eventIdx++) {
        string eventLine = in.events[eventIdx];
        out += "=== EVENT " + to_string(eventIdx + 1) + ": " + eventLine + " ===\n";
        
        // Parse event
        stringstream ss(eventLine);
        string eventType;
        ss >> eventType;
        
        int eventDay;
        ss >> eventDay;
        
        // TODO: Process different event types
        if (eventType == "WEATHER") {
            // Add weather block
        }
        else if (eventType == "DROP") {
            // Deactivate user
        }
        else if (eventType == "FATIGUE") {
            // Update user energy
        }
        else if (eventType == "BUDGET") {
            // Update user budget
        }
        
        // TODO: Re-plan from eventDay to D
        // Keep days 1..eventDay-1 as they were
        // Mark activities used in days 1..eventDay-1 as used
        // Plan days eventDay..D with updated constraints
        
        // TODO: Output new plan for days eventDay to D
    }
    
    return out;
}




//complete
static string solve(Input in) {
    string out;
    out += "=== PLAN ===\n";
    
    // Track which activities have been used
    set<int> usedActivities;
    
    // Track weather blocks (day -> set of blocked tags)
    map<int, set<string>> weatherBlocks;
    
    // Store results for each day
    vector<pair<vector<int>, pair<int, int>>> dailyPlans; // {ids, {cost, satisfaction}}
    
    // Helper lambda to get min budget among active users
    auto getMinBudget = [&]() -> int {
        int minBudget = INT_MAX;
        for (const auto& user : in.users) {
            if (user.active) {
                minBudget = min(minBudget, user.budget);
            }
        }
        return minBudget;
    };
    
    // Helper lambda to get min energy among active users
    auto getMinEnergy = [&]() -> int {
        int minEnergy = INT_MAX;
        for (const auto& user : in.users) {
            if (user.active) {
                minEnergy = min(minEnergy, user.energy);
            }
        }
        return minEnergy;
    };
    
    // Helper lambda to calculate satisfaction
    auto calculateSatisfaction = [&](const vector<int>& ids) -> int {
        int sat = 0;
        for (int id : ids) {
            const auto& act = in.activities.at(id);
            int count = 0;
            for (const auto& user : in.users) {
                if (user.active && user.tags.count(act.tag)) {
                    count++;
                }
            }
            sat += count;
        }
        return sat;
    };
    
    // Helper lambda to check if activity is eligible
    auto isEligible = [&](int day, const Activity& act) -> bool {
        if (usedActivities.count(act.id)) return false;
        if (weatherBlocks.count(day) && weatherBlocks[day].count(act.tag)) return false;
        return true;
    };
    
    // Helper lambda to find best plan for a single day
    auto findBestPlan = [&](int day) -> pair<vector<int>, pair<int, int>> {
        vector<Activity*> eligible;
        for (auto& [id, act] : in.activities) {
            if (isEligible(day, act)) {
                eligible.push_back(&act);
            }
        }
        
        int n = eligible.size();
        vector<int> bestIds;
        int bestCost = 0, bestSat = -1;
        
        // Iterate over all subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> currentIds;
            int totalCost = 0, totalEnergy = 0, totalDuration = 0;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentIds.push_back(eligible[i]->id);
                    totalCost += eligible[i]->cost;
                    totalEnergy += eligible[i]->energy;
                    totalDuration += eligible[i]->duration;
                }
            }
            
            int minBudget = getMinBudget();
            int minEnergy = getMinEnergy();
            
            if (totalCost <= minBudget && totalEnergy <= minEnergy && totalDuration <= in.H) {
                int satisfaction = calculateSatisfaction(currentIds);
                
                // Compare with best
                if (bestSat == -1 || satisfaction > bestSat) {
                    bestSat = satisfaction;
                    bestCost = totalCost;
                    bestIds = currentIds;
                } else if (satisfaction == bestSat) {
                    if (totalCost < bestCost) {
                        bestCost = totalCost;
                        bestIds = currentIds;
                    } else if (totalCost == bestCost) {
                        sort(currentIds.begin(), currentIds.end());
                        sort(bestIds.begin(), bestIds.end());
                        if (currentIds < bestIds) {
                            bestIds = currentIds;
                        }
                    }
                }
            }
        }
        
        if (bestSat == -1) {
            return {{}, {0, 0}};
        }
        return {bestIds, {bestCost, bestSat}};
    };
    
    // Initial planning for all days
    for (int day = 1; day <= in.D; day++) {
        auto [ids, costSat] = findBestPlan(day);
        for (int id : ids) {
            usedActivities.insert(id);
        }
        dailyPlans.push_back({ids, costSat});
    }
    
    // Output initial plan
    for (int day = 1; day <= in.D; day++) {
        out += formatDay(day, dailyPlans[day-1].first, dailyPlans[day-1].second.first, dailyPlans[day-1].second.second) + "\n";
    }
    
    // Process events
    for (size_t eventIdx = 0; eventIdx < in.events.size(); eventIdx++) {
        string eventLine = in.events[eventIdx];
        out += "=== EVENT " + to_string(eventIdx + 1) + ": " + eventLine + " ===\n";
        
        // Parse event
        stringstream ss(eventLine);
        string eventType;
        ss >> eventType;
        
        int eventDay;
        ss >> eventDay;
        
        if (eventType == "WEATHER") {
            string tag;
            ss >> tag;
            weatherBlocks[eventDay].insert(tag);
        }
        else if (eventType == "DROP") {
            string name;
            ss >> name;
            for (auto& user : in.users) {
                if (user.name == name) {
                    user.active = false;
                    break;
                }
            }
        }
        else if (eventType == "FATIGUE") {
            string name;
            int newEnergy;
            ss >> name >> newEnergy;
            for (auto& user : in.users) {
                if (user.name == name) {
                    user.energy = newEnergy;
                    break;
                }
            }
        }
        else if (eventType == "BUDGET") {
            string name;
            int newBudget;
            ss >> name >> newBudget;
            for (auto& user : in.users) {
                if (user.name == name) {
                    user.budget = newBudget;
                    break;
                }
            }
        }
        
        // Re-plan from eventDay onward
        usedActivities.clear();
        
        // Keep activities used before eventDay
        for (int day = 1; day < eventDay; day++) {
            for (int id : dailyPlans[day-1].first) {
                usedActivities.insert(id);
            }
        }
        
        // Plan from eventDay to D
        for (int day = eventDay; day <= in.D; day++) {
            auto [ids, costSat] = findBestPlan(day);
            for (int id : ids) {
                usedActivities.insert(id);
            }
            dailyPlans[day-1] = {ids, costSat};
        }
        
        // Output from eventDay to D
        for (int day = eventDay; day <= in.D; day++) {
            out += formatDay(day, dailyPlans[day-1].first, dailyPlans[day-1].second.first, dailyPlans[day-1].second.second) + "\n";
        }
    }
    
    return out;
}