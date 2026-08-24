#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void make_plans(
    int key_index,
    const std::vector<std::string>& keys,
    const std::unordered_map<std::string, std::vector<std::string>>& synonyms,
    std::unordered_map<std::string, std::string>& plan,
    std::vector<std::unordered_map<std::string, std::string>>& plans) {
    const std::string& key = keys[key_index];

    for (const std::string& value : synonyms.at(key)) {
        plan[key] = value;
        if (plan.size() == synonyms.size()) {
            plans.push_back(plan);
            plan.erase(key);
        } else {
            make_plans(key_index + 1, keys, synonyms, plan, plans);
            plan.erase(key);
        }
    }
}
