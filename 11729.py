N = int(input())
count = 0


def hanoi(n, start, assistant, goal):
    global count
    if n == 1:
        print(start, " ", goal)
        count += 1
        return
    hanoi(n-1, start, goal, assistant)
    print(start, " ", goal)
    count += 1
    hanoi(n-1, assistant, start, goal)


hanoi(N, 1, 2, 3)
print(count)