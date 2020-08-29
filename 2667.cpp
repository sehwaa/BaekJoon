#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 26

int matrix[MAX][MAX];
bool visited[MAX][MAX];

int coX[] = {-1, 1, 0, 0};
int coY[] = {0, 0, -1, 1};
int N;

vector <int> answer;
int c;

void dfs(int x, int y) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int px = x + coX[i];
    int py = y + coY[i];

    if (px >= 0 && py >= 0 && !visited[px][py] && matrix[px][py] == 1) {
      dfs(px, py);
      c++;
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &matrix[i][j]);
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && matrix[i][j] == 1) {
        c = 1;
        dfs(i,j);
        answer.push_back(c);
      }
    }
  }

  cout << answer.size() << endl;
  sort(answer.begin(), answer.end());

  for (int i = 0; i < answer.size(); i++) {
    cout << answer.at(i) << endl;
  }
  return 0;
}