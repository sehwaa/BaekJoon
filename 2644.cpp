#include <iostream>
#include <vector>

using namespace std;

#define MAX 101
int n,m;
vector<int> relationship[MAX];
bool visited[MAX];
bool findEnd = false;
int answer = 0;

void dfs(int p1, int p2) {
  visited[p1] = true;
  for (int i = 0; i < relationship[p1].size(); i++) {
    if (findEnd) return;
  	if (relationship[p1][i] == p2) {
  		findEnd = true;
  		break;
  	}
    if (!visited[relationship[p1][i]]) {
    	answer++;
    	dfs(relationship[p1][i], p2);
    }
  }
  if (!findEnd) answer--;
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
    visited[parent] = false;
    visited[child] = false;
  }

  dfs(p1, p2);
  if (findEnd)	cout << answer+1;
  else cout << -1;
  return 0;
}