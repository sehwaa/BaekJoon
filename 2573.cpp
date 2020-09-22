#include <cstdio>

using namespace std;

#define MAX 301
int N,M;
int freeze[MAX][MAX];
bool visited[MAX][MAX][MAX];
int year = 0;

int coX[4] = {-1, 1, 0, 0};
int coY[4] = {0, 0, -1, 1};

void after1year(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int px = x + coX[i];
    int py = y + coY[i];

    if (px >= 0 && py >=0 && freeze[px][py] == 0 && freeze[x][y] > 0) {
      freeze[x][y] -= 1;
      if (freeze[x][y] <= 0 ) freeze[x][y] = -1;
    }
  }
}

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int px = x + coX[i];
    int py = y + coY[i];
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &freeze[i][j]);
    }
  }

  for (int i = 1; i < N-1; i++) {
    for (int j = 1; j < M-1; j++) {
      after1year(i, j);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d", freeze[i][j]);
    }
    printf("\n");
  }
  return 0;
}