import heapq

def sum_of_first_k_prime_powers(primes: list[int], k: int)->int:
    max_heap = []
    for i in range(1, k+1):
        is_updated = False
        for p in primes:
            if len(max_heap) < k:
                heapq.heappush(max_heap, -p**i)
                is_updated = True
            else:
                if -max_heap[0] > p**i:
                    heapq.heappop(max_heap)
                    heapq.heappush(max_heap, -p**i)
                    is_updated = True

        if not is_updated:
            return -sum(max_heap)

    return -sum(max_heap)

if __name__ == "__main__":
    # Example1
    primes = [2]
    k = 1
    print(sum_of_first_k_prime_powers(primes, k))
    # Example2
    primes = [5]
    k = 3
    print(sum_of_first_k_prime_powers(primes, k))
    # Example3
    primes = [2, 3]
    k = 7
    print(sum_of_first_k_prime_powers(primes, k))