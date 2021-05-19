n = input()
n = n if int(n) >= 10 else "0"+n
new_n = None
cnt = 0


def make_new_n(list_new_n: list) -> str:
    su = map(int, list(list_new_n))
    sum_right_su = list(str(sum(su)))[-1]
    right_su = str(list(list_new_n)[-1])
    return right_su + sum_right_su


while n != new_n:
    if new_n is None:
        new_n = make_new_n(n)
    else:
        new_n = make_new_n(new_n)
    cnt += 1

print(cnt)
