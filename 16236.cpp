#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int shark[21][21];
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> shark[i][j];
    }
  }
  return 0;
}