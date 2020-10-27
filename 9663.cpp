#include <iostream>

using namespace std;

#define MAX 15

int N;
int caseCnt = 0;
int queenCnt = 0;
int cnt = 0;
int chess[MAX*MAX][MAX][MAX];
int coX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int coY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int findQueen(int x, int y) {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 8; j++) {
			int px = x + (coX[j] * i);
			int py = y + (coY[j] * i);
			if (px >= 0 && px < N && py >= 0 && py < N && chess[cnt][px][py] == 1) {
				return -1;
			}
		}
	}
	return 0;
}

void attack(int x, int y) {
	queenCnt++;
	chess[cnt][x][y] = 1;
	
	for (int i = x+1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == y) continue;
			int result = findQueen(i, j);
			if (result == 0) {
				attack(i, j);
				if (queenCnt == N) caseCnt++;
				queenCnt--;
				chess[cnt][i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			attack(i,j);
			queenCnt = 0;
			cnt++;
		}
	}
	
	cout << caseCnt;
	return 0;
}
