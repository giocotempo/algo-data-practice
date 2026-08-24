CORRECT_PASSWORD = "bc"
def check_password(s: str)->bool:
    return s == CORRECT_PASSWORD

def white_hat_hacker(max_length: int) -> str:
    elements = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    res = ""

    def backtrack(cur: list):
        nonlocal res
        if len(cur) >= max_length:
            return

        for e in elements:
            if e not in cur:
                cur.append(e)
                print(cur)
                if check_password("".join(cur)):
                    res = "".join(cur)
                    return
                else:
                    backtrack(cur)

                cur.pop()
            
            if res != "":
                return

    backtrack([])
    return res

if __name__ == "__main__":
    print(white_hat_hacker(4))

