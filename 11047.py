N, K = map(int, input().split())

coins = sorted([int(input()) for _ in range(N)], reverse=True)

answer = 0
for c in coins:
    if K <= 0:
        break
    if K >= c and K > 0:
        answer += (K//c)
        K -= c * (K//c)
        
print(answer)