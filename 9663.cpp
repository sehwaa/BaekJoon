#include <iostream>
#include <stack>

using namespace std;

#define MAX 15

int N;
int coX[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int coY[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int queenCnt = 0;
int caseCnt = 0;
int queen[MAX][MAX];
bool visited[MAX][MAX];
stack< pair<int, int> > s;

void attack(int x, int y) {
	
	for (int i = 0; i < 8; i++) {
		int px = x + coX[i];
		int py = y + coY[i];
		
		if (px >= 0 && py >= 0 && px < N && py < N) {
			if (queen[px][py] == 1) {
				return;
			}
		}
	}
	
	queen[x][y] = 1;
	s.push(make_pair(x, y));
	
	if (s.size() == N) {
		caseCnt++;
		s.pop();
		queen[x][y] = 0;
		return;
	}
	
	while(!s.empty()) {
		for (int i = x; i < N; i++) {
			for (int j = y; j < N; j++) {
				if (i == x && i == y) continue;
				else attack(i, j);
			}
		}
		
		if (s.size() > 0) {
			s.pop();
			queen[x][y] = 0;
		}
	}
	return;
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			attack(i, j);
		}
	}
	
	cout << caseCnt;
	return 0;
}
