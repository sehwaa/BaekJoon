N = int(input())

su_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]


def dp() -> int:
    if N < 10:
        return su_list[N]

    idx = 1
    while len(su_list) < N + 1:
        if len(su_list) <= idx:
            return -1
        for s in range(0, int(su_list[idx][-1])):
            desc = su_list[idx] + su_list[s]
            su_list.append(su_list[idx] + su_list[s])
            if len(su_list) == N + 1:
                return su_list[-1]
        idx += 1

    return su_list[-1]


print(dp())
