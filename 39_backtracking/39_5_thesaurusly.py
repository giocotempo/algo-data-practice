def thesaurusly(sentence: str, synonyms: dict[str, list[str]])->list[str]:
    res = []
    plans = []
    key_indices = {i: key for i, key in enumerate(synonyms.keys())}


    def make_plans(key_index: int, plan: dict[str, str] = {}):
        for val in synonyms[key_indices[key_index]]:
            plan[key_indices[key_index]] = val
            if len(plan) == len(synonyms):
                plans.append(plan.copy())
                plan.pop(key_indices[key_index])
            else:
                make_plans(key_index + 1, plan)
                plan.pop(key_indices[key_index])

    make_plans(0)

    for plan in plans:
        sentence_copy = sentence
        for key, val in plan.items():
            sentence_copy = sentence_copy.replace(key, val)

        res.append(sentence_copy)

    return res

if __name__ == "__main__":
    sentence = "one does not simply walk into mordor"
    synonyms = {
        "walk": ["stroll", "hike", "wander"],
        "simply": ["just", "merely"]
    }
    print(thesaurusly(sentence, synonyms))