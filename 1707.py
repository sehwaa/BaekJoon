from collections import deque
import sys

K = int(sys.stdin.readline())


def bfs(node_list, v):
    visited = [False for _ in range(v+1)]

    queue = deque()
    queue.append(1)

    while len(queue) != 0:
        n = queue.popleft()
        visited[n] = True

        for cn in node_list[n]:
            if cn in queue:
                return False

            if not visited[cn]:
                queue.append(cn)

    return True


for _ in range(K):
    info = sys.stdin.readline().rstrip()
    V = int(info[0])
    E = int(info[2])
    node = [[] for _ in range(V+1)]
    for _ in range(E):
        n1, n2 = list(map(int, input().split()))
        node[n1].append(n2)
        node[n2].append(n1)

    if bfs(node, V):
        print("YES")
    else:
        print("NO")