#include <iostream>
#include <vector>

using namespace std;

#define MAX 16

int L, C;
vector<int> v[MAX];
bool visited[MAX][MAX];
char a[MAX];

void recursive(int index) {
  if (v[index].size() != 0) {
    for (int i = 0; i < v[index].size(); i++) {
      if (!visited[index][v[index][i]]) {
        visited[index][v[index][i]] = true;
        recursive(v[index][i]);
      }
    }
  } else {
    return;
  }
}

int main() {
  cin >> L >> C;

  for (int i = 0; i < C; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      if (i == j) {
        continue;
      } else {
        if (a[i] <= a[j]) {
          v[i].push_back(j);
        }
      }
    }
  }

  for (int i = 0; i < C; i++) {
    recursive(i);
  }
  return 0;
}