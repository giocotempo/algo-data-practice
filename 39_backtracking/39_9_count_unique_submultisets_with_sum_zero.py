def count_unique_submultisets_with_sum_zero(S: list[int])->int:
    res = 1
    candidates = []
    freq_map = {}
    for num in S:
        if num not in freq_map:
            freq_map[num] = 1
            candidates.append(num)
        else:
            freq_map[num] += 1

    def backtrack(subset: list[int], start_index: int):
        nonlocal res
        
        for i, num in enumerate(candidates):
            if i < start_index:
                continue

            for j in range(1, freq_map[num] + 1):
                for _ in range(j):
                    subset.append(num)

                if sum(subset) == 0:
                    res += 1

                backtrack(subset.copy(), i + 1)

                for _ in range(j):
                    subset.pop()
    
    backtrack([], 0)

    return res

if __name__ == "__main__":
    # Example1
    S = [1, 1, -1, -1]
    print(count_unique_submultisets_with_sum_zero(S))
    # Example2
    S = []
    print(count_unique_submultisets_with_sum_zero(S))
    # Example3
    S = [-1, 2, 1, 0, 3]
    print(count_unique_submultisets_with_sum_zero(S))