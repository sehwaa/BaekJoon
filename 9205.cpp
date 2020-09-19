#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 103
int n;
vector< pair<int, int> > adj[MAX];
vector< pair<int, int> > dist[MAX];
bool visited[MAX][MAX];
bool happy = false;

void dfs(int index, int start) {
  if (index == n+1) {
    happy = true;
    return;
  }
  visited[start][index] = true;
  for (int i = 0; i < dist[index].size(); i++) {
    if (!visited[index][dist[index][i].first]) {
      dfs(dist[index][i].first, index);
    }
  }
}

void beer() {
  for (int i = 1; i < n; i++) {
    int distX = abs(adj[0].front().first - adj[i].front().first);
    int distY = abs(adj[0].front().second - adj[i].front().second);
    dist[0].push_back(make_pair(i, distX+distY));
  }

  for (int i = 0; i < dist[0].size(); i++) {
    for (int j = 1; j < n; j++) {
      if (dist[0][i].first != j) {
        int distX = abs(adj[dist[0][i].first].front().first - adj[j].front().first);
        int distY = abs(adj[dist[0][i].first].front().second - adj[j].front().second);
        if (distX+distY <= 1000) dist[dist[0][i].first].push_back(make_pair(j, distX+distY));
      }
    }
  }

  for (int i = 0; i < dist[0].size(); i++) {
    dfs(dist[0][i].first, 0);
    if (happy) {
      cout << "happy";
      return;
    }
  }
  cout << "sad";
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n+2; j++) {
      int x, y;
      cin >> x >> y;
      adj[j].push_back(make_pair(x,y));
    }
    beer();
  }
  return 0;
}