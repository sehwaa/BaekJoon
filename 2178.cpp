#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{

  int N;
  int M;
  cin >> N >> M;
    
  int array[N][M];
  int visited[N][M];

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
        scanf("%1d", &array[i][j]);
        visited[i][j] = 0;
    }
  }

  queue< pair<int, int> > q;
  q.push(make_pair(0,0));

  visited[0][0] = 1;

  int coX[] = {1, 0, -1, 0};
  int coY[] = {0, 1, 0, -1};

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    if (x == N-1 && y == M-1) {
      cout << visited[x][y];
      break;
    }

    for (int i = 0; i < 4; i++) {
      int px = x + coX[i];
      int py = y + coY[i];

      if (px >= 0 && px < N && py >= 0 && py < M) {
        if (visited[px][py] == 0 && array[px][py] == 1) {
          q.push(make_pair(px, py));
          visited[px][py] = visited[x][y] + 1;
        }
      }
    }
  }

  return 0;
}