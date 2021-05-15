n = int(input())
score = list(map(int, input().split()))
new_score = [s/max(score)*100 for s in score]
print(sum(new_score)/len(new_score))
