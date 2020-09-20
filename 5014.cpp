#include <iostream>
#include <queue>

using namespace std;

#define UP 0
#define DOWN 1
#define MAX 1000000

int F,S,G,U,D;
int visited[MAX+1];

int bfs() {
	queue<int> q;
	q.push(S);
	visited[S] = 1;
	
	while (!q.empty()) {
		int floor = q.front();
		if (floor == G) {
			return visited[floor] - 1;
		}
		
		q.pop();
		
		for (int i = 0; i < 2; i++) {
			int next = 0;
			switch (i) {
				case UP:
					next = floor + U;
					break;
				case DOWN:
					next = floor - D;
					break;
			}
			if (next > 0 && next <= F && visited[next] == 0) {
				q.push(next);
				visited[next] = visited[floor] + 1;
			}
		}
	}
	return -1;
}

int main(){
	cin >> F >> S >> G >> U >> D;
	
	int answer = bfs();
	if (answer == -1) cout << "use the stairs";
	else cout << answer;
    return 0;
}