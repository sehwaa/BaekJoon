N = int(input())


def print_star(n):
    if n == 1:
        return ["*"]

    n = n // 3

    stars = print_star(n)

    s = []
    for star in stars:
        s.append(star * 3)
    for star in stars:
        s.append(star + " " * n + star)
    for star in stars:
        s.append(star * 3)

    return s


print("\n".join(print_star(N)))
