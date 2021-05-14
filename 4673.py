def d(n: int) -> int:
    return int(n) + sum(list(map(int, list(str(n)))))


d_list = [d(idx) for idx in range(1, 10000)]
num_list = [idx for idx in range(1, 10000)]
d_sub_num = [num for num in num_list if num not in d_list]

for num in d_sub_num:
    print(num)
