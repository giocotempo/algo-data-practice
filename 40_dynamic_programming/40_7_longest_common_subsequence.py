def longest_common_subsequence(s1: str, s2: str)->int:
    dp = [[0] *(len(s2) + 1) for _ in range(len(s1) + 1)]
    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                dp[i+1][j+1] = dp[i][j] + 1
            else:
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

    return dp[-1][-1]

if __name__ == "__main__":
    # Example1
    s1 = "HAHAH"
    s2 = "AAAAHH"
    print(longest_common_subsequence(s1, s2))
    # Example2
    s1 = ""
    s2 = "AA"
    print(longest_common_subsequence(s1, s2))
    # Example3
    s1 = "ABCBDAB"
    s2 = "BDCABA"
    print(longest_common_subsequence(s1, s2))
