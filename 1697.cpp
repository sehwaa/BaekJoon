#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000
#define BEFORE 0
#define AFTER 1
#define AFTER2 2

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
    
    for (int i = 0; i < 3; i++) {
      int there;
      switch (i) {
        case BEFORE:
          there = node - 1;
          break;
        case AFTER:
          there = node + 1;
          break;
        case AFTER2:
          there = node * 2;
          break;
      } 
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

  bfs(N);

  return 0;
}