def insertion_sort(nums: list[int])->list[int]:
    for i in range(1, len(nums)):
        insert(i, nums)

    return nums

def insert(p: int, nums: list[int])->None:
    while p > 0:
        if nums[p] < nums[p-1]:
            nums[p], nums[p-1] = nums[p-1], nums[p]
            p -= 1
        else:
            break

if __name__ == "__main__":
    nums = [6, 8, 4, 2, 7, 3, 1, 5]
    print(insertion_sort(nums))