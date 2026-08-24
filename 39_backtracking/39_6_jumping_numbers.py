def jumping_numbers(n: int):
    res = []
    def backtrack(num: str):
        if int(num) not in res and int(num) < n:
            res.append(int(num))
            if int(num[-1]) > 0:
                backtrack(num[-1] + str(int(num[-1])-1))
            
            if int(num[-1]) < 9:
                backtrack(num[-1] + str(int(num[-1])+1))
    
    for i in range(1, 10):
        backtrack(str(i))

    return res

if __name__ == "__main__":
    n = 34
    print(jumping_numbers(n))