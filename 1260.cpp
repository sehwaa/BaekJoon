#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<int> > adj;
vector<bool> visited;

void dfs(int here) {
  cout << here + 1 << " ";
  visited[here] = true;

  for (int i = 0; i < adj[here].size(); i++) {
    int there = adj[here][i];
    if (there == -1) continue;
    if (!visited[there]) {
      dfs(there);
    }
  }
}

void bfs(int here) {
  queue < int > q;
  q.push(here);
  visited[here] = true;

  while(!q.empty()) {
    int start = q.front();
    cout << start  + 1 << " ";
    q.pop();

    for (int j = 0; j < adj[start].size(); j++) {
      int there = adj[start][j];
      if (there == -1) continue;
      if (!visited[there]) {
        q.push(there);
        visited[there] = true;
      }
    }
  }
}

int main() {
  int node;
  int edge;
  int start;
  cin >> node >> edge >> start;

  adj.assign(node, vector<int>(1, -1));
  visited = vector<bool>(adj.size(), false);

  for (int i = 0; i < edge; i++) {
    int pair1, pair2;
    cin >> pair1 >> pair2;    
    adj[pair1 - 1].push_back(pair2 - 1);
    adj[pair2 - 1].push_back(pair1 - 1);
  }

  for (int i = 0; i < node; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(start - 1);
  cout << endl;

  visited = vector<bool>(adj.size(), false);
  bfs(start - 1);

  return 0;
}