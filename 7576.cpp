#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
int **tomato = new int*[N];
int **visited = new int*[N];

queue< pair<int, int> > q;

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};

int answer = 0;

void bfs() {
  while(!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int px = cx + coX[i];
      int py = cy + coY[i];

      if (px >= 0 && py >= 0 && px < N && py < M && visited[px][py] == 0 && tomato[px][py] == 0) {
        visited[px][py] = visited[cx][cy] + 1;
        q.push(make_pair(px, py));
        answer = visited[px][py];
      }
    }
  }
}

int main() {
  cin >> M >> N;

  int value;

  for (int i = 0; i < N; i++) {
    tomato[i] = new int[M];
    visited[i] = new int[M];
    for (int j = 0; j < M; j++) {
      cin >> value;
      tomato[i][j] = value;
      visited[i][j] = 0;
      if (value == 1) {
        q.push(make_pair(i, j));
        visited[i][j] = 1;
      }
    }
  }

  bfs ();

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] == 0 && tomato[i][j] == 0) {
        answer = -1;
      }
    }
  }

  if (answer == 0 || answer == -1) cout << answer;
  else  cout << answer - 1;
  
  return 0;
}