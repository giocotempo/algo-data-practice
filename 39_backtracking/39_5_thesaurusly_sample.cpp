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

std::string replace_all(std::string text, const std::string& from, const std::string& to) {
    std::size_t start_pos = 0;

    while ((start_pos = text.find(from, start_pos)) != std::string::npos) {
        text.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }

    return text;
}

std::vector<std::string> thesaurusly(
    const std::string& sentence,
    const std::unordered_map<std::string, std::vector<std::string>>& synonyms,
    const std::vector<std::string>& keys) {
    std::vector<std::string> result;

    if (synonyms.empty()) {
        result.push_back(sentence);
        return result;
    }

    std::vector<std::unordered_map<std::string, std::string>> plans;
    std::unordered_map<std::string, std::string> plan;
    make_plans(0, keys, synonyms, plan, plans);

    for (const std::unordered_map<std::string, std::string>& current_plan : plans) {
        std::string sentence_copy = sentence;

        for (const std::string& key : keys) {
            sentence_copy = replace_all(sentence_copy, key, current_plan.at(key));
        }

        result.push_back(sentence_copy);
    }

    return result;
}

int main() {
    std::string sentence = "one does not simply walk into mordor";
    std::unordered_map<std::string, std::vector<std::string>> synonyms = {
        {"walk", {"stroll", "hike", "wander"}},
        {"simply", {"just", "merely"}}
    };
    std::vector<std::string> keys = {"walk", "simply"};

    std::vector<std::string> result = thesaurusly(sentence, synonyms, keys);

    std::cout << "[";
    for (std::size_t i = 0; i < result.size(); ++i) {
        std::cout << "\"" << result[i] << "\"";
        if (i + 1 < result.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
