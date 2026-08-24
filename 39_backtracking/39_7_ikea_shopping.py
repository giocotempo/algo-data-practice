def ikea_shopping(budget: int, prices: list[int], ratings: list[float])->list[int]:
    res = []
    cur = []
    cur_max = 0
    cur_total_price = 0
    cur_total_rating = 0

    def back_track():
        nonlocal res, cur, cur_max, cur_total_price, cur_total_rating

        for i in range(len(prices)):
            if i not in cur:
                cur.append(i)
                cur_total_price += prices[i]
                cur_total_rating += ratings[i]

                if cur_total_price < budget:
                    back_track()
                
                if cur_total_price <= budget and cur_total_rating > cur_max:
                    cur_max = cur_total_rating
                    res = cur.copy()
                
                cur.pop()
                cur_total_rating -= ratings[i]
                cur_total_price -= prices[i]
    back_track()

    return res


if __name__ == "__main__":
    # Example1
    budget = 20
    prices = [10, 5, 15, 8, 3]
    ratings = [7.0, 3.5, 9.0, 6.0, 2.0]
    print(ikea_shopping(budget, prices, ratings))
    # Example2
    budget = 10
    prices = [2, 3, 4, 5]
    ratings = [1.0, 2.0, 3.5, 4.0]
    print(ikea_shopping(budget, prices, ratings))
