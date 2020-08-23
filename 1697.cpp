#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000
vector< vector<int> > adj;
vector<int> visited;
int N;
int K;
int answer = 0;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    if (node == K) {
      cout << visited[node] - 1;
      break;
    }
    
    for (int i = 0; i < adj[node].size(); i++) {
      int there = adj[node][i];
      if (there == -1) continue;
      if (there >= 0 && there <= MAX && visited[there] == 0) {
        q.push(there);
        visited[there] = visited[node] + 1;
      }
    }
  }
}

int main() {
  cin >> N >> K;

  adj.assign(MAX, vector<int>(1, -1));
  visited = vector<int>(MAX, 0);

  for (int i = N-1; i <= K + 1; i++) {
    adj[i].push_back(i-1);
    adj[i].push_back(i+1);
    adj[i].push_back(2*i);
  }

  bfs(N);

  return 0;
}