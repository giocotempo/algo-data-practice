def bubble_sort(nums: list[int])->list[int]:
    if len(nums) <= 1:
        return nums
    l, r = 0, 1
    while r < len(nums):
        if nums[l] > nums[r]:
            nums[l], nums[r] = nums[r], nums[l]
        l += 1
        r += 1

    sorted_nums = bubble_sort(nums[:-1]) 
    sorted_nums.append(nums[-1])
    return sorted_nums

if __name__ == "__main__":
    nums = [6, 8, 4, 2, 7, 3, 1, 5]
    print("bubble:   ", bubble_sort(nums))
    