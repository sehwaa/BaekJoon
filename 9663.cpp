#include <iostream>

using namespace std;

#define MAX 15

int N;
int coX[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int coY[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int queenCnt = 0;
int caseCnt = 0;
int queen[MAX][MAX];
bool visited[MAX][MAX];

void attack(int x, int y) {
	cout << "queen x: " << x << " y : " << y << endl;
	queen[x][y] = 1;
	visited[x][y] = true;
	queenCnt++;
	
	if (queenCnt == N) {
		caseCnt++;
		cout << "case Count : " << caseCnt << endl;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (queen[i][j] == 1) continue;
			if (i - x <= 1 && j - y <= 1 || queen[i][j] == -1) {
				queen[i][j] = -1;
				continue;
			} else {
				if (!visited[i][j]) {
					cout << "new queen x: " << i << " y: " << j << endl;
					attack(i, j);
					queen[i][j] = 0;
					for (int k = 0; k < 8; k++) {
						int px = i + coX[k];
						int py = j + coY[k];
						if (px >= 0 && py >= 0 && px < N && py < N && queen[i][j] == -1) {
							queen[px][py] = 0;
						}
					}
					queenCnt--;
				}
			}
		}
	}
	return;
}

int main() {
	cin >> N;
		
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "start x: " << i << " y: " << j << endl;
			attack(i, j);
		}
	}
	
	cout << caseCnt;
	return 0;
}
