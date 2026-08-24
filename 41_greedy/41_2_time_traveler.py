def time_traveler(jumping_points: list[int], k: int, max_aging: int)->bool:
    for i in range(len(jumping_points)-1):
        time_diff = jumping_points[i+1] - jumping_points[i]
        if time_diff >= max_aging:
            if k > 0:
                k -= 1
            else:
                max_aging -= time_diff
        else:
            max_aging -= time_diff

    return max_aging >= 0

if __name__ == "__main__":
    # Example1
    jumping_points = [2020, 2024]
    k = 0
    max_aging = 3
    print(time_traveler(jumping_points, k, max_aging))
    # Example2
    jumping_points = [2020, 2024]
    k = 1
    max_aging = 1
    print(time_traveler(jumping_points, k, max_aging))
    # Example3
    jumping_points = [1803, 1861, 1863, 1865, 1920, 1929, 1941, 1964, 2001, 2021]
    k = 4
    max_aging = 45
    print(time_traveler(jumping_points, k, max_aging))