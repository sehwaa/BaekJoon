C = int(input())

for _ in range(C):
    score = list(map(int, input().split()))
    n, score = score[0], score[1:]
    avg = sum(score) / len(score)
    print(format((len(list(filter(lambda x: x > avg, score)))/n)*100, ".3f")+"%")