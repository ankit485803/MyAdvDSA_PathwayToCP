

/*

https://www.hackerrank.com/contests/goldman-sachs-india-hackathon-2026-cs/challenges/json-typescript-type-generator




*/


// Input : line 1 = T; then per case: line A = root name, line B = compact JSON.
// Output: per-case blocks joined by a line `---`, ending with one '\n'.

#include <bits/stdc++.h>
using namespace std;

static string solve(const string& rootName, const string& jsonText) {
    (void)rootName; (void)jsonText;
    // TODO: implement.
    throw runtime_error("solve() not implemented");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    string out;
    for (int i = 0; i < t; i++) {
        string rootName, jsonText;
        getline(cin, rootName);
        getline(cin, jsonText);
        if (i > 0) out += "\n---\n";
        out += solve(rootName, jsonText);
    }
    out += '\n';

    cout << out;
    return 0;
}




static string solve(const string& rootName, const string& jsonText) {

    // ============================================
    // STEP 1:
    // Parse JSON string into data structure
    // ============================================

    // Example:
    // json arr = json::parse(jsonText);




    // ============================================
    // STEP 2:
    // Create structures to store:
    // ============================================

    // 1. Interface definitions
    // 2. Field types
    // 3. Optional fields
    // 4. Interface name mapping
    // 5. Used interface names




    // ============================================
    // STEP 3:
    // Traverse ALL objects
    // ============================================

    // For each object:
    //   visit every key
    //   detect value type:
    //
    //      string
    //      number
    //      boolean
    //      null
    //      object
    //      array
    //
    // merge field information globally




    // ============================================
    // STEP 4:
    // Handle nested OBJECTS
    // ============================================

    // Interface name rule:
    //
    // key[0].toUpperCase() + key.substr(1)
    //
    // Examples:
    // address -> Address
    // userProfile -> UserProfile
    //
    // Handle collisions:
    // Address
    // Address2
    // Address3




    // ============================================
    // STEP 5:
    // Handle ARRAYS
    // ============================================

    // Arrays may contain:
    //
    // primitives
    // objects
    // mixed types
    //
    // Build:
    //
    // number[]
    // string[]
    // (number | string)[]
    // unknown[]
    // Posts[]
    // (Posts | number)[]




    // ============================================
    // STEP 6:
    // Merge TYPES
    // ============================================

    // Example:
    //
    // string + null
    // => null | string
    //
    // object + null
    // => Address | null
    //
    // sort lexicographically ASCII




    // ============================================
    // STEP 7:
    // Detect OPTIONAL fields
    // ============================================

    // if field absent in any object:
    //
    // field?: type;




    // ============================================
    // STEP 8:
    // Generate FINAL interfaces
    // ============================================

    // Format:
    //
    // export interface RootType {
    //   age: number;
    // }




    // ============================================
    // STEP 9:
    // Sort interfaces by ASCII order
    // ============================================

    // print with EXACT formatting




    // ============================================
    // RETURN FINAL STRING
    // ============================================

    string ans;

    return ans;
}




static string solve(const string& rootName, const string& jsonText) {

    size_t pos = 0;
    SimpleJSON root = SimpleJSON::parse(jsonText, pos);

    // ============================================
    // EMPTY ARRAY CASE
    // ============================================

    if (root.arrayValue.empty()) {
        return "export interface " + rootName + " {}";
    }

    // ============================================
    // DATA STRUCTURES
    // ============================================

    struct FieldInfo {
        int presentCount = 0;
        set<string> types;
    };

    struct InterfaceInfo {
        map<string, FieldInfo> fields;
        int objectCount = 0;
    };

    map<string, InterfaceInfo> interfaces;

    map<string, string> pathToInterface;

    set<string> usedNames;

    usedNames.insert(rootName);

    pathToInterface[""] = rootName;

    // ============================================
    // NAME GENERATOR
    // ============================================

    auto makeInterfaceName = [&](const string& key) {

        string base =
            string(1, toupper(key[0])) + key.substr(1);

        string name = base;

        int suffix = 2;

        while (usedNames.count(name)) {
            name = base + to_string(suffix++);
        }

        usedNames.insert(name);

        return name;
    };

    // ============================================
    // DFS FUNCTION
    // ============================================

    function<string(
        const SimpleJSON&,
        const string&,
        const string&
    )> processValue;

    processValue =
        [&](const SimpleJSON& val,
            const string& key,
            const string& path) -> string {

        // ====================================
        // PRIMITIVES
        // ====================================

        if (val.isString()) return "string";

        if (val.isNumber()) return "number";

        if (val.isBoolean()) return "boolean";

        if (val.isNull()) return "null";

        // ====================================
        // OBJECT
        // ====================================

        if (val.isObject()) {

            string objPath = path;

            if (!pathToInterface.count(objPath)) {

                string name = makeInterfaceName(key);

                pathToInterface[objPath] = name;
            }

            string interfaceName =
                pathToInterface[objPath];

            interfaces[objPath].objectCount++;

            for (auto &[childKey, childVal]
                 : val.objectValue) {

                interfaces[objPath]
                    .fields[childKey]
                    .presentCount++;

                string childType =
                    processValue(
                        childVal,
                        childKey,
                        objPath + "/" + childKey
                    );

                interfaces[objPath]
                    .fields[childKey]
                    .types.insert(childType);
            }

            return interfaceName;
        }

        // ====================================
        // ARRAY
        // ====================================

        if (val.isArray()) {

            if (val.arrayValue.empty()) {
                return "unknown[]";
            }

            set<string> elemTypes;

            for (const auto& elem : val.arrayValue) {

                string elemType =
                    processValue(
                        elem,
                        key,
                        path + "/[]"
                    );

                elemTypes.insert(elemType);
            }

            vector<string> types(
                elemTypes.begin(),
                elemTypes.end()
            );

            sort(types.begin(), types.end());

            string unionType;

            for (int i = 0; i < (int)types.size(); i++) {

                if (i) unionType += " | ";

                unionType += types[i];
            }

            if (types.size() == 1) {

                return unionType + "[]";
            }

            return "(" + unionType + ")[]";
        }

        return "unknown";
    };

    // ============================================
    // PROCESS ROOT OBJECTS
    // ============================================

    interfaces[""].objectCount =
        root.arrayValue.size();

    for (const auto& obj : root.arrayValue) {

        for (const auto& [key, val]
             : obj.objectValue) {

            interfaces[""]
                .fields[key]
                .presentCount++;

            string type =
                processValue(
                    val,
                    key,
                    "/" + key
                );

            interfaces[""]
                .fields[key]
                .types.insert(type);
        }
    }

    // ============================================
    // GENERATE OUTPUT
    // ============================================

    vector<pair<string,string>> output;

    vector<pair<string,string>> orderedInterfaces;

    for (auto &[path, name] : pathToInterface) {

        orderedInterfaces.push_back({name, path});
    }

    sort(
        orderedInterfaces.begin(),
        orderedInterfaces.end()
    );

    for (auto &[name, path] : orderedInterfaces) {

        string s =
            "export interface " + name;

        auto &info = interfaces[path];

        if (info.fields.empty()) {

            s += " {}";

            output.push_back({name, s});

            continue;
        }

        s += " {\n";

        for (auto &[field, fieldInfo]
             : info.fields) {

            bool optional =
                fieldInfo.presentCount
                < info.objectCount;

            vector<string> types(
                fieldInfo.types.begin(),
                fieldInfo.types.end()
            );

            sort(types.begin(), types.end());

            string typeStr;

            for (int i = 0;
                 i < (int)types.size();
                 i++) {

                if (i) typeStr += " | ";

                typeStr += types[i];
            }

            s += "  " + field;

            if (optional) s += "?";

            s += ": " + typeStr + ";\n";
        }

        s += "}";

        output.push_back({name, s});
    }

    // ============================================
    // FINAL STRING
    // ============================================

    string ans;

    for (int i = 0; i < (int)output.size(); i++) {

        if (i) ans += "\n\n";

        ans += output[i].second;
    }

    return ans;
}