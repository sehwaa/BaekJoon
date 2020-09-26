#include <cstdio>

using namespace std;

#define MAX 301

int N, M;
int freeze[MAX][MAX];
bool visited[MAX][MAX];
int year = 1;

int coX[4] = {-1, 1, 0, 0};
int coY[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int px = x + coX[i];
    int py = y + coY[i];

    if (px > 0 && py > 0 && !visited[px][py] && freeze[px][py] > 0) {
      visited[px][py] = true;
      dfs(px, py);
    }
  }
}

int melt() {
  int cnt = 0;
  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {
      if (freeze[i][j] > 0) {
        for (int k = 0; k < 4; k++) {
          int px = i + coX[k];
          int py = j + coY[k];
          if (px >= 0 && py >= 0 && freeze[px][py] == 0) {
            freeze[i][j] -= 1;
            if (freeze[i][j] == 0) freeze[i][j] = -1;
          }
        }
      }
    }
  }

  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {
      if (!visited[i][j] && freeze[i][j] > 0) {
        dfs(i,j);
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &freeze[i][j]);
      visited[i][j] = false;
    }
  }

  bool allMelt = false;
  while(!allMelt) {
    int num = melt();
    if (num >= 2) break;
    if (num == 0) {
      allMelt = true;
      break;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        visited[i][j] = false;
      }
    }
    year++;
  }

  if (allMelt) printf("%d", 0);
  else printf("%d", year);
  return 0;
}