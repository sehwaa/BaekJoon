N = int(input())

t = sorted([tuple(map(int, input().split())) for _ in range(0, N)], key=lambda x: (x[1], x[0]))

def count_meeting():
    m = []
    for v in t:
        start = v[0]
        if len(m) == 0 or start >= m[-1][1]:
            m.append(v)
    return len(m)

print(count_meeting())