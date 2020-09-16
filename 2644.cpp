#include <iostream>
#include <vector>

using namespace std;

#define MAX 101
int n,m;
vector<int> relationship[MAX];

void dfs(int p1, int p2) {
  
}

int main() {
  cin >> n;
  
  int p1, p2;
  cin >> p1 >> p2;

  cin >> m;

  for (int i = 0; i < m; i++) {
    int parent,child;
    cin >> parent >> child;
    relationship[parent].push_back(child);
    relationship[child].push_back(parent);
  }
  return 0;
}