from collections import defaultdict

N = int(input())
apple_tree = list(input())
rotten_apple = list(map(int, input().split()))
apple_relationship = defaultdict(list)

sequence = 0
apples = []
for num in range(0, len(apple_tree)):
    if num == len(apple_tree) - 1:
        apple_tree[num] = apples.pop()
        break
    if apple_tree[num] == '1':
        leaf_node = apples.pop()
        apple_tree[num] = leaf_node
        apple_relationship[apples[-1]].append(leaf_node)
        continue
    sequence += 1
    apples.append(sequence)
    apple_tree[num] = sequence

rotten_apples = [apple_tree[rotten_apple[0] - 1], apple_tree[rotten_apple[1] - 1]]


def search(key):
    for k, v in apple_relationship.items():
        if key in v:
            if rotten_apples[0] in v:
                return k
            search(k)
            return


co = search(rotten_apples[1])
parent = co if co is not None else 1

answer = []
for idx, apple in enumerate(apple_tree):
    if apple == parent:
        answer.append(idx + 1)

print(" ".join(map(str, answer)))
