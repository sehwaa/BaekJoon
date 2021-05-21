test_case = int(input())

for _ in range(test_case):
    quiz_result = input()
    quiz_result = quiz_result.split("X")
    score = 0
    for o in quiz_result:
        if len(o) > 0:
            score += ((1 + len(o)) * len(o)) / 2

    print(int(score))