#include <iostream>
#include <vector>

using namespace std;

#define MAX 51
int cabbage[MAX][MAX];
bool visited[MAX][MAX];

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};

int answer = 0;
vector< int > v;

void dfs (int x, int y) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int px = x + coX[i];
    int py = y + coY[i];

    if (px >= 0 && py >= 0 && !visited[px][py] && cabbage[px][py] == 1) {
      dfs(px, py);
    }
  }
}

int main()
{
  int T;
  cin >> T;

  int M, N, K;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> K;

    answer = 0;
    for (int ci = 0; ci < N; ci++) {
      for (int cj = 0; cj < M; cj++) {
        cabbage[ci][cj] = 0;
        visited[ci][cj] = false;
      }
    }

    int x, y;
    for (int j = 0; j < K; j++) {
      cin >> x >> y;
      cabbage[y][x] = 1;
    }

    for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
        if (!visited[n][m] && cabbage[n][m] == 1) {
          dfs(n, m);
          answer++;
        }
      }
    }

    v.push_back(answer);
  }

  for (int i = 0; i < v.size(); i++) {
    cout<< v.at(i) << endl;
  }
  return 0;
}