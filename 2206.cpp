#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001];

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};

int breakWall = 0;

int bfs(int x, int y) {
  queue< pair<int, int> > q;
  q.push(make_pair(x, y));
  visited[x][y] = 1;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    if (cx == N && cy == M) return visited[cx][cy];

    for (int i = 0; i < 4; i++) {
      int px = cx + coX[i];
      int py = cy + coY[i];

      if (px >= 0 && py >=0 && visited[px][py] == 0) {
        if (map[cx][cy] ==1 && map[px][py] == 0) {
          q.push(make_pair(px, py));
          if (breakWall == 0) breakWall++;
        }
        visited[px][py] = visited[cx][cy] + 1;
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
      visited[i][j] = 0;
    }
  }

  cout << bfs(0,0);
  return 0;
}