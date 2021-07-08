N = int(input())
output = []


def hanoi(n, start, assistant, goal):
    if n == 1:
        output.append(start + " " + goal)
        return

    hanoi(n-1, start, goal, assistant)
    output.append(start + " " + goal)
    hanoi(n-1, assistant, start, goal)


hanoi(N, "1", "2", "3")
print(len(output))
print("\n".join(output))