#include <iostream>

using namespace std;

#define MAX 51
int cabbage[MAX][MAX];
bool visited[MAX][MAX];

int answer = 0;
int M;
int N;
int K;

void dfs(int x, int y) {
  visited[x][y] == true;

  int coX[4] = {-1, 1, 0, 0};
  int coY[4] = {0, 0, -1, 1};

  for (int i = 0; i < 4; i++) {
    int px = x + coX[i];
    int py = y + coY[i];

    if (px >= 0 && py >= 0 && px < N && py < M) {
      if (cabbage[px][py] == 1 && !visited[px][py]) {
        dfs(px, py);
      }
    }
  }
}

int main()
{
  int T;

  cin >> T ;

  for (int i = 0; i < T; i++) {    
    answer = 0;
    cin >> M >> N >> K;

    for (int ci = 0; ci < N; ci++) {
      for (int cj = 0; cj < M; cj++) {
        cabbage[ci][cj] = 0;
        visited[ci][cj] = false;
      }
    }

    int X;
    int Y;

    for (int j = 0; j < K; j++) {
      cin >> X >> Y;
      if (X >= 0 && Y >= 0 && Y <M && X < N) {
        cabbage[Y][X] = 1;
      }
    }

    for (int ci = 0; ci < N; ci++) {
      for (int cj = 0; cj < M; cj++) {
        if (!visited[ci][cj] && cabbage[ci][cj] == 1) {
          dfs(ci, cj);
          answer++;
        }
      }
    }

    cout << answer << endl;
  }
  return 0;
}