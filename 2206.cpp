#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001][2];

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};

int bfs(int x, int y) {
  queue< pair< pair<int, int>, int > > q;

  q.push(make_pair(make_pair(x,y), 0));
  visited[0][0][0] = 1;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int wall = q.front().second;
    q.pop();
    
    if (cx == N-1 && cy == M-1) return visited[N-1][M-1][wall];

    for (int i = 0; i < 4; i++) {
      int px = cx + coX[i];
      int py = cy + coY[i];
      
      if (px >= 0 && py >= 0 && px < N && py < M && visited[px][py][wall] == 0) {
        if (map[px][py] == 0) {
          visited[px][py][wall] = visited[cx][cy][wall] + 1; 
          q.push(make_pair(make_pair(px, py), wall)); 
        }
        else if (map[px][py] == 1 && wall == 0) {
          visited[px][py][1] = visited[cx][cy][wall] + 1; 
          q.push(make_pair(make_pair(px, py), 1)); 
        }
      }
    }
  }
  return -1;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  cout << bfs(0,0);
  return 0;
}