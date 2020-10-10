#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 901

int K, N, F;
bool relationship[MAX][MAX];
vector<int> group;

void findFriends(int friend1) {
	if (group.size() > 0) {
		for (int i = 0; i < group.size(); i++) {
			if (!relationship[friend1][group[i]]) {
				return;
			}
		}
		group.push_back(friend1);
		return;
	} else {
		group.push_back(friend1);
	}
	
	for (int i = 1; i <= N; i++) {
		if (friend1 == i) continue;
		if (relationship[friend1][i]) {
			findFriends(i);
		}
	}
}

int main() {
	cin >> K >> N >> F;
	
	for (int i = 0; i < F; i++) {
		int friend1, friend2;
		cin >> friend1 >> friend2;
		relationship[friend1][friend2] = true;
		relationship[friend2][friend1] = true;
	}
	
	for (int i = 1; i <= N; i++) {
		findFriends(i);
		if (group.size() < K) {
			while (group.size() != 0) {
				group.pop_back();
			}
		} else {
			sort(group.begin(), group.end());
			for (int j = 0; j < K; j++) {
				cout << group.at(j) << endl;
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}
