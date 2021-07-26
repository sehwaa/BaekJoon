T = int(input())


def factorial(b: int) -> int:
    if b <= 1:
        return 1
    return b * factorial(b-1)


for _ in range(0, T):
    N, M = map(int, input().split())
    result = factorial(N) / (factorial(N - M) * factorial(M)) if N > M else factorial(M) / (factorial(M - N) * factorial(N))
    print(int(result))

