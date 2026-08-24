def reconstruct_longest_common_subsequence(s1: str, s2: str):
    dp = {}
    for i in range(len(s1)+1):
        dp[(i, 0)] = ""
    for j in range(len(s2)+1):
        dp[(0, j)] = ""

    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                dp[(i+1, j+1)] = dp[(i, j)] + s1[i]
            else:
                if len(dp[(i+1, j)]) >= len(dp[(i, j+1)]):
                    dp[(i+1, j+1)] = dp[(i+1, j)]
                else:
                    dp[(i+1, j+1)] = dp[(i, j+1)]

    return dp[(len(s1), len(s2))]

if __name__ == "__main__":
    # Example1
    s1 = "HAHAH"
    s2 = "AAAAHH"
    print(reconstruct_longest_common_subsequence(s1, s2))
    # Example2
    s1 = ""
    s2 = "AA"
    print(reconstruct_longest_common_subsequence(s1, s2))