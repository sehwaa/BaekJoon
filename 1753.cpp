#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MAX_V 20001
int V, E;
vector< pair<int, int> > adj[MAX_V];

vector<int> dijkstra(int src) {
  vector<int> dist(V+1, 3000000);
  dist[src] = 0;
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int cost = pq.top().first;
    int here = pq.top().second;
    pq.pop();

    if (dist[here] < cost) continue;

    for (int i = 0; i < adj[here].size(); i++) {
      int there = adj[here][i].first;
      int nextDist = cost + adj[here][i].second;

      if (dist[there] > nextDist) {
        dist[there] = nextDist;
        pq.push(make_pair(nextDist, there));
      }
    }
  }
  return dist;
}

int main() {
  int start;
  scanf("%d %d", &V, &E);
  scanf("%d", &start);
  
  for (int i = 0; i < E; i++) {
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(make_pair(v, w));
  }

  vector<int> result = dijkstra(start);
  for(int i = 1; i <= V; i++) {
    if (result[i] == 3000000) printf("%s\n", "INF");
    else if (i == start) printf("%d\n", 0);
    else printf("%d\n", result[i]);
  }
  return 0;
}