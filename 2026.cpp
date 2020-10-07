#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 901
#define FRIEND1 0
#define FRIEND2 1

int K, N, F;
bool relationship[MAX][MAX];
bool visited[MAX][MAX];
vector<int> group;
int cnt = 1;

int findFriends(int friend1, int friend2) {
	visited[friend1][friend2] = true;
	
	if (group.size() == K) {
		sort(group.begin(), group.end());
		for (int i = 0; i < group.size(); i++) {
			cout << group[i] << endl;
		}
		return 1;
	}
	
	if (group.size() == 0) {
		//이거 두개는 무조건 들어가서 얘네돌고도 또 돌게 만들어야 할듯
		group.push_back(friend1);
		group.push_back(friend2);
	} else {
		for (int i = 0; i < 2; i++) {
			int count = 0;
			for (int j = 0; j < group.size(); j++) {
				if (i == FRIEND1) {
					if (group[j] == friend1 || !relationship[friend1][group[j]] && !relationship[group[j]][friend1]) {
						count = -1;
						break;
					}
				} else if (i == FRIEND2) {
					if (group[j] == friend2 || !relationship[friend2][group[j]] && !relationship[group[j]][friend2]) {
						count = -1;
						break;
					}
				}
			}
			if (count != -1 && i == FRIEND1) group.push_back(friend1);
			else if (count != -1 && i == FRIEND2) group.push_back(friend2);
		}
		
	}
	return -1;
}

int main() {
	cin >> K >> N >> F;
	
	for (int i = 0; i < F; i++) {
		int friend1, friend2;
		cin >> friend1 >> friend2;
		relationship[friend1][friend2] = true;
		relationship[friend2][friend1] = true;
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && relationship[i][j]) {
				result = findFriends(i,j);
				if (result == 1) return 0;
			}
		}
	}
	
	cout << -1;
	return 0;
}