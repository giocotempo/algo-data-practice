import random


def quick_sort(nums: list[int]) -> list[int]:
    """Return a sorted copy of nums using quick sort."""
    if len(nums) <= 1:
        return nums.copy()

    pivot_index = random.randrange(len(nums))
    pivot = nums[pivot_index]
    remaining = nums[:pivot_index] + nums[pivot_index + 1 :]

    lower = []
    upper = []
    for num in remaining:
        if num <= pivot:
            lower.append(num)
        else:
            upper.append(num)

    return quick_sort(lower) + [pivot] + quick_sort(upper)


def bubble_sort(nums: list[int]) -> list[int]:
    """Return a sorted copy of nums using bubble sort."""
    result = nums.copy()

    for end in range(len(result) - 1, 0, -1):
        swapped = False
        for index in range(end):
            if result[index] > result[index + 1]:
                result[index], result[index + 1] = result[index + 1], result[index]
                swapped = True

        # The list was already sorted, so no more passes are necessary.
        if not swapped:
            break

    return result


def insertion_sort(nums: list[int]) -> list[int]:
    """Return a sorted copy of nums using insertion sort."""
    result = nums.copy()

    for index in range(1, len(result)):
        value = result[index]
        position = index - 1

        while position >= 0 and result[position] > value:
            result[position + 1] = result[position]
            position -= 1

        result[position + 1] = value

    return result


def selection_sort(nums: list[int]) -> list[int]:
    """Return a sorted copy of nums using selection sort."""
    result = nums.copy()

    for index in range(len(result) - 1):
        smallest_index = index

        for candidate in range(index + 1, len(result)):
            if result[candidate] < result[smallest_index]:
                smallest_index = candidate

        result[index], result[smallest_index] = (
            result[smallest_index],
            result[index],
        )

    return result


def sort_array(nums: list[int]) -> list[int]:
    """Keep the original interface, using quick sort by default."""
    return quick_sort(nums)


if __name__ == "__main__":
    nums = [6, 8, 4, 2, 7, 3, 1, 5]

    print("quick:    ", quick_sort(nums))
    print("bubble:   ", bubble_sort(nums))
    print("insertion:", insertion_sort(nums))
    print("selection:", selection_sort(nums))
