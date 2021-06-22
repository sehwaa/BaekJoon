N = int(input())
star = []


def print_star(s, su):
    if su * 3 > N:
        s.split("\n")
        return

    su *= 3

    temp = ""
    for i in range(0, 3):
        for j in range(0, 3):
            if i != 1 or j != 1:
                temp += s
            else:
                temp += " "
        temp += "\n"

    print_star(temp, su)


print_star("*", 1)
