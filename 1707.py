K = int(input())
    
for _ in range(K):
    V, E = map(int, input().split())
    
    nodes = [[] for _ in range(V)]
    visited = [False] * V
    colors = {i:'r' for i in range(V)}
    
    for _ in range(E):
        u,v = map(int, input().split())
        nodes[u-1].append(v-1)
        nodes[v-1].append(u-1)
        
    def search(node_idx):
     visited[node_idx] = True
        for v in nodes[node_idx]:
            if visited[v] == False:
                if colors[node_idx] == 'r':
                    colors[v] = 'b'
                search(v)
                
    search(0)
    
    def result():
        for idx, adj in enumerate(nodes):
            for n in adj:
                if colors[idx] == colors[n]:
                    print('NO')
                    return
        print('YES')
        return
    
    result()