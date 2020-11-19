#include <iostream>
 
using namespace std;
 
char sit[5][5];
bool visited[5][5];
int coX[4] = {-1, 1, 0, 0};
int coY[4] = {0, 0, -1, 1};
int som = 0; int yeon = 0;
int answer = 0;
 
void dfs(int x, int y) {
	visited[x][y] = true;
 
	if (som + yeon == 7) {
		answer++;
		return;
	}
 
	for (int i = 0; i < 4; i++) {
		int px = x + coX[i];
		int py = y + coY[i];
 
		if (px >= 0 && py >= 0 && px < 5 && py < 5 && !visited[px][py]) {
			if (sit[px][py] == 'S') som++;
			else yeon++;
 
			if (yeon >= 4) {
				yeon--;
			} else {
				dfs (px, py);
				visited[px][py] = false;
				if (sit[px][py] == 'S') som--;
      			else yeon--;
			}
		}
	}
	
	visited[x][y] = false;
}
 
int main() {
 
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> sit[i][j];
			visited[i][j] = false;
		}
	}
 
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (sit[i][j] == 'S') som++;
			else yeon++;
			dfs(i,j);
			som = 0; yeon = 0;
		}
	}
	
	cout << answer;
	return 0;
}
