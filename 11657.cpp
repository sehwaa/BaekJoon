#include <cstdio>
#include <vector>

using namespace std;

#define MAX_V 500
vector< pair<int, int> > adj[MAX_V];
int N, M;

vector<long long> bellmanFord(int src) {
  vector<long long> upper(N+1, 10000*6000);
  upper[src] = 0;
  bool updated;

  for (int iter = 1; iter <= N; iter++) {
    updated = false;
    for (int here = 1; here <= N; here++) {
      for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i].first;
        int cost = adj[here][i].second;
        if (upper[there] > upper[here] + cost) {
          upper[there] = upper[here] + cost;
          updated = true;
        }
      }
    }
    if (!updated) break;
  }
  if (updated) upper.clear();
  return upper;
}

int main() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < M; i++) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    adj[A].push_back(make_pair(B, C));
  }

  vector<long long> result = bellmanFord(1);
  if (result.size() == 0) {
    printf("%d", -1);
  } else {
    for (int i = 2; i <= N; i++) {
      if (result[i] == 10000*6000) printf("%d\n", -1);
      else printf("%d\n", result[i]);
    }
  }
  return 0;
}