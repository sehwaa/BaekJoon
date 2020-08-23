#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > adj;
vector<bool> visited;
int answer = 0;

void dfs(int here) {
  visited[here] = true;

  for (int i = 0; i < adj[here].size(); i++) {
    int there = adj[here][i];
    if (there == -1) continue;
    if (!visited[there]) {
      dfs(there);
      answer++;
    }
  }
}

int main()
{
  int N, E;
  cin >> N;
  cin >> E;

  adj.assign(N, vector<int>(E, -1));

  for (int i = 0; i < E; i++) {
    int pair1, pair2;
    cin >> pair1 >> pair2;
    adj[pair1 - 1].push_back(pair2 - 1);
    adj[pair2 - 1].push_back(pair1 - 1);
  }

  visited = vector<bool>(adj.size(), false);

  dfs(0);

  cout << answer;
  return 0;
}