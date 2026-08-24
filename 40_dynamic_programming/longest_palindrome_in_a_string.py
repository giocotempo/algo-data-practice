def longest_palindrome_in_a_string(s: str)->str:
    memo = [[None] * len(s) for _ in range(len(s))]
    for i in range(len(s)):
        memo[i][i] = True

    longest_palindrome = ""

    def rec(i, j)->bool:
        nonlocal longest_palindrome
        if memo[i][j]:
            return memo[i][j]
        
        if i > j:
            return True
        
        if s[i] == s[j]:
            memo[i][j] = rec(i+1, j-1)
            if memo[i][j] is True and j-i+1 > len(longest_palindrome):
                longest_palindrome = s[i:j+1]
        else: 
            memo[i][j] = False
        
        return memo[i][j]
    
    for i in range(len(s)):
        for j in range(i, len(s)):
            rec(i, j)

    return longest_palindrome

if __name__ == "__main__":
    s = "abccbaba"
    print(longest_palindrome_in_a_string(s))

    s = "abccbccbagf"
    print(longest_palindrome_in_a_string(s))