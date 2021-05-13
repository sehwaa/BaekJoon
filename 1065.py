N = input()


def find_hansu(n: int) -> bool:
    su_list = list(map(int, list(str(n))))
    if len(su_list) == 1:
        return True
    else:
        sub = [su_list[i + 1] - su_list[i] for i in range(0, len(su_list) - 1)]
        if len(set(sub)) == 1:
            return True
        return False


ans = 0
for idx in range(1, int(N) + 1):
    if find_hansu(idx) is True:
        ans += 1

print(ans)
