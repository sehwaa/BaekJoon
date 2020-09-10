#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int N, M;
int **map;
int **visited;

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};

int bfs(int x, int y) {
  queue< pair< pair<int, int>, int > > q;
  q.push(make_pair(make_pair(x,y), 1));
  visited[0][0] = 1;

  while (!q.empty()) {
    int cx = q.front().first.first;  
    int cy = q.front().first.second;
    int wall = q.front().second;
    q.pop();
    
    if (cx == N-1 && cy == M-1) return visited[N-1][M-1];

    for (int i = 0; i < 4; i++) {
      int px = cx + coX[i];
      int py = cy + coY[i];
      int breakwall = wall;
      
      if (px >= 0 && py >= 0 && px < N && py < M && !visited[px][py] && breakwall >= 0) {
        if (map[px][py] == 1) breakwall--;
        q.push(make_pair(make_pair(px, py), breakwall));
        visited[px][py] = visited[cx][cy] + 1;
      }
    }
  }
  return -1;
}

int main() {
  cin >> N >> M;

  map = new int *[N];
  visited = new int *[N];

  for (int i = 0; i < N; i++) {
    map[i] = new int[M];
    visited[i] = new int[M];
    for (int j = 0; j < M; j++) {
      scanf("%1d", &map[i][j]);
      visited[i][j] = 0;
    }
  }

  cout << bfs(0,0);
  return 0;
}