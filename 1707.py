K = int(input())

for _ in range(K):
    V, E = map(int, input().split())

    nodes = [[] for _ in range(V)]
    visited = [1] + [0] * (V-1)

    for _ in range(E):
        u, v = map(int, input().split())
        nodes[u - 1].append(v - 1)
        nodes[v - 1].append(u - 1)


    def search(node_idx):
        for v in nodes[node_idx]:
            if visited[v] == 0:
                if visited[node_idx] == 1:
                    visited[v] = 2
                elif visited[node_idx] == 2:
                    visited[v] = 1
                s = search(v)
                if not s:
                    return False
            elif visited[node_idx] == visited[v]:
                return False
        return True

    result = search(0)
    print("YES") if result == True else print("NO")


