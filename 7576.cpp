#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
int **tomato = new int*[N];
int **visited = new int*[N];

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};

void bfs(int x, int y) 
{
  queue<pair<int, int>> q;
  q.push(make_pair(x,y));
  visited[x][y] = 1;

  while(!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int px = cx + coX[i];
      int py = cy + coY[i];

      if (px >= 0 && py >= 0 && px < N && py < M && visited[px][py] == 0 && tomato[px][py] != -1) {
        visited[px][py] = visited[cx][cy] + 1;
        q.push(make_pair(px, py));
      }
    }
  }
}

int main()
{
  cin >> M >> N;

  int value;
  vector< pair<int, int> > ripeTomato;
  for (int i = 0; i < N; i++) {
    tomato[i] = new int[M];
    visited[i] = new int[M];
    for (int j = 0; j < M; j++) {
      cin >> value;
      tomato[i][j] = value;
      visited[i][j] = 0;
      if (value == 1) ripeTomato.push_back(make_pair(i, j));
    }
  }

  for (int i = 0; i < ripeTomato.size(); i++) {
    bfs (ripeTomato.at(i).first, ripeTomato.at(i).second);
  }

  for (int i = 0; i < N; i++) {
    delete []tomato[i];
  }

  delete []tomato;

  return 0;
}