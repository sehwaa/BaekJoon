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
	cout << "search in f: " << f << endl;
	cout << "search in fixIndex: " << fixIndex << endl;
	visited[fixIndex][f] = true;

	//중복일 때 count...세야함...
	//그리고 로직 다시 짜야할듯... (비교를 이렇게게하면 처음에
	//만들어진 애들 4명만 답이 나올수 밖에 없음)
	//왜냐하면, k_friends랑 groups[f]랑 비교하니까 전부다 일치할수가 없음
	//완전탐색으로 다 돌면서 체크하는 로직으로 해야할듯
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
	
	cout << "cnt : " << cnt << endl;
	if (cnt != k_friends[fixIndex].size()) {
		k_friends[fixIndex].pop_back();
		return;
	} else {
	}
	
	if (k_friends[fixIndex].size() == K){
		sort(k_friends[fixIndex].begin(), k_friends[fixIndex].end());
		if (answer != 0) {
			for (int i = 0; i < K; i++) {
				cout << "answer : " << answer << endl;
				if (k_friends[answer][i] >= k_friends[fixIndex][i]) {
					cout << "fixIndex : " << fixIndex << endl;
					answer = fixIndex;
					break;
				}
			}
		}
		else {
			answer = fixIndex;
			cout << "answer: " << answer << endl;
			cout << "fixIndex: " << fixIndex << endl;
		}
		
		//erase
		for (int i = 0; i < K; i++) {
			cout << k_friends[answer][i] << endl;
		}
		return;
	}

	for (vector<int>::iterator it = groups[f].begin(); it != groups[f].end(); it++) {
		if (!visited[fixIndex][*it]) {
			k_friends[fixIndex].push_back(*it);
			search(*it);
		}
	}
	
	return;
}

int main() {
	cin >> K >> N >> F;

	for (int i = 0; i < F; i++) {
		int f1, f2;
		cin >> f1 >> f2;
		groups[f1].push_back(f2);
		groups[f2].push_back(f1);
	}

	//erase
	for (int i = 1; i <= N; i++) {
		cout << "=============" << endl;
		cout << i << " : ";
		for (int j = 0; j < groups[i].size(); j++) {
			cout << groups[i][j];
		}
		cout << endl;
	}
	
	for (int i = 1; i <= N; i++) {
		fixIndex = i;
		for (int j = 0; j < N; j++) {
			if (!visited[fixIndex][j]) {
				k_friends[fixIndex].push_back(j+1);
				search(j+1);
			}
		}
	}
	
	if (answer != 0) {
		for (int i = 0; i < K; i++) {
			cout << k_friends[answer][i] << endl;
		}
		return 0;
	}
	cout << -1;
	return 0;
}