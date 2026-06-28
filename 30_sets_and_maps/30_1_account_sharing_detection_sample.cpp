#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>

using namespace std;

string account_sharing_detection(const vector<pair<string, string>>& connections) {
    unordered_set<string> hashmap;

    for (const auto& connection : connections) {
        const string& ip = connection.first;
        const string& user = connection.second;

        if (hashmap.find(user) != hashmap.end()) {
            return ip;
        } else {
            hashmap.insert(user);
        }
    }

    return "";
}

int main() {
    // Example1
    vector<pair<string, string>> connections1 = {
        {"203.0.113.10", "mike"},
        {"298.51.100.25", "bob"},
        {"292.0.2.5", "mike"},
        {"203.0.113.15", "bob2"}
    };
    cout << account_sharing_detection(connections1) << endl;

    // Example2
    vector<pair<string, string>> connections2 = {
        {"111.0.0.0", "mike"},
        {"111.0.0.1", "mike"},
        {"111.0.0.2", "bob"},
        {"111.0.0.3", "bob"}
    };
    cout << account_sharing_detection(connections2) << endl;

    // Example3
    vector<pair<string, string>> connections3 = {
        {"111.0.0.0", "mike"},
        {"111.0.0.1", "mike2"},
        {"111.0.0.2", "mike3"},
        {"111.0.0.3", "mike4"}
    };
    cout << account_sharing_detection(connections3) << endl;

    return 0;
}
