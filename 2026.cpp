#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 901
int K, N, F;
vector<int> groups[MAX];
bool visited[MAX][MAX];
int fixIndex = 0;
vector<int> k_friends[MAX];
int answer = 0;

void search(int f) {
	visited[fixIndex][f] = true;

	if (k_friends[fixIndex].size() > 2) {
		int cnt = 1;
		for (vector<int>::iterator it = k_friends[fixIndex].begin(); it != k_friends[fixIndex].end(); it++) {
			bool exist = false;
			for (vector<int>::iterator it2 = groups[f].begin(); it2 != groups[f].end(); it2++) {
				if (*it == *it2) {
					exist = true;
				}
				if (exist) {
					cnt++;
					break;
				}
			}
		}
		if (cnt != k_friends[fixIndex].size()) {
			k_friends[fixIndex].pop_back();
			return;
		}
	}

	if (k_friends[fixIndex].size() == K) {
		if (answer != 0) {
			for (int i = 0; i < K; i++) {
				if (k_friends[answer][i] > k_friends[fixIndex][i]) {
					answer = fixIndex;
					break;
				}
			}
		}
		else {
			answer = fixIndex;
		}
		sort(k_friends[fixIndex].begin(), k_friends[fixIndex].end());
		return;
	}

	for (vector<int>::iterator it = groups[f].begin(); it != groups[f].end(); it++) {
		if (!visited[fixIndex][*it]) {
			k_friends[fixIndex].push_back(*it);
			search(*it);
		}
	}
}

int main() {
	cin >> K >> N >> F;

	for (int i = 0; i < F; i++) {
		int f1, f2;
		cin >> f1 >> f2;
		groups[f1].push_back(f2);
		groups[f2].push_back(f1);
	}

	for (int i = 1; i <= N; i++) {
		fixIndex = i;
		for (int j = 1; j <= N; j++) {
			if (!visited[fixIndex][j]) {
				k_friends[fixIndex].push_back(j);
				search(j);
			}
		}
	}

	for (int i = 0; i < K; i++) {
		cout << k_friends[fixIndex][i] << endl;
	}

	cout << -1;
	return 0;
}