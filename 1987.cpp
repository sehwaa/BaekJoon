#include <iostream>
#include <map>

using namespace std;

int R, C;
char **board;
map <char, bool> visited;
int coX[4] = {-1, 1, 0, 0};
int coY[4] = {0, 0, -1, 1};
int count = 0;
int maxCount = 0;

void dfs(int x, int y) {
    visited[board[x][y]] = true;
    count++;

    for (int i = 0; i < 4; i++) {
        int px = x + coX[i];
        int py = y + coY[i];

        if (px >= 0 && py >= 0 && px < R && py < C && !visited[board[px][py]]) {
            dfs(px, py);
            visited[board[px][py]] = false;
            count--;
        }

        if (maxCount < count) maxCount = count;
    }
}

int main() {
    cin >> R >> C;

    board = new char *[R];
    for (int i = 0; i < R; i++) {
        board[i] = new char[C];
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (visited.find(board[i][j]) != visited.end()) {
                visited.insert(make_pair(board[i][j], false));
            }
        }
    }

    dfs(0,0);

    cout << maxCount << endl;
    return 0;
}