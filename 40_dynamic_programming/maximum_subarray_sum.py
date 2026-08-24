def maximum_subarray_sum(nums: list[int])->int:
    dp = [[0] * len(nums) for _ in range(len(nums))]
    for i in range(len(nums)):
        dp[i][i] = nums[i]

    res = 0
    for i in range(len(nums)):
        for j in range(i, len(nums)):
            dp[i][j] = dp[i][j-1] + nums[j]
            if dp[i][j] > res:
                res = dp[i][j]
    
    return res

if __name__ == "__main__":
    nums = [3, 1, -6, 2, -1, 4, -9]
    print(maximum_subarray_sum(nums))