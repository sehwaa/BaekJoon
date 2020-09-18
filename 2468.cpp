#include <cstdio>

using namespace std;

#define MAX 101

int N;
int area[MAX][MAX];
bool visited[MAX][MAX][MAX];

int COX[4] = {-1, 1, 0, 0};
int COY[4] = {0, 0, -1, 1};

int answer = 0;
int maxRain = 0;

void dfs(int x, int y, int rain) {
	for (int i = 0; i < 4; i++) {
		int px = x + COX[i];
		int py = y + COY[i];
		if (px >= 0 && py >= 0 && !visited[rain][px][py] && area[px][py] > rain) {
			visited[rain][px][py] = true;
			dfs(px, py, rain);
		}
	}
}

int main() {
	scanf("%d\n", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d ", &area[i][j]);
			if (maxRain < area[i][j]) maxRain = area[i][j];
		}
	}
	
	for (int r = maxRain+1; r >= 0; r--) {
		int safeZone = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[r][i][j] && area[i][j] > r) {
					visited[r][i][j] = true;
					dfs(i,j,r);
					safeZone++;
				}
			}
		}
		if (answer < safeZone) answer = safeZone;
	}
	
	printf("%d", answer);
	return 0;
}