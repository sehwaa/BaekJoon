#include <iostream>
#include <queue>

using namespace std;

int tomato[101][101][101];
int visited[101][101][101];
int M, N, H;

int coX[6] = {1, -1, 0, 0, 0, 0};
int coY[6] = {0, 0, 1, -1, 0, 0};
int coZ[6] = {0, 0, 0, 0, 1, -1};

queue< pair<pair<int, int>, int> > q;
int answer = 0;

int bfs() {
  while(!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int cz = q.front().second;
    
    q.pop();

    for (int i = 0; i < 6; i++) {
      int px = cx + coX[i];
      int py = cy + coY[i];
      int pz = cz + coZ[i];

      if (px >= 0 && py >= 0 && pz >= 0 && px < N && py < M && pz < H && visited[px][py][pz] == 0) {
        if (tomato[px][py][pz] == 0) {
          q.push(make_pair(make_pair(px, py), pz));
          visited[px][py][pz] = visited[cx][cy][cz] + 1;
          answer = visited[px][py][pz];
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < H; k++) {
        if (visited[i][j][k] == 0 && tomato[i][j][k] == 0) {
          return -1;
        }
      }
    }
  }

  if (answer == 0) return 0;
  else  return answer;
}

int main() {
  cin >> M >> N >> H;

  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
          cin >> tomato[i][j][k];
          visited[i][j][k] = 0;
          if (tomato[i][j][k] == 1) {
            q.push(make_pair(make_pair(i,j),k));
        }
      }
    }
  }

  cout << bfs();
  return 0;
}