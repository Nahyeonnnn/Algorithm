#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// |a - x| ≤ 2이고 |b - y| ≤ 2이면 (x, y)에서 (a, b)로 이동
// 2 +a => x => a -2
// 2 +b => y => - 2 +b
// 암벽의 정상 y = t


int main() {
    int n, t; //홈 갯수, 정상 위치
    cin >> n >> t;
    queue<pair<int, int>> Q;
    vector<pair<int, int>> rockWall(n);

    int maxX=0;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        rockWall[i] = make_pair(x, y);
        if (maxX < x) maxX = x;
    }

    vector<vector<int>> board(maxX+1, vector<int>(t+1, 0));
    vector<vector<bool>> vis(maxX+1, vector<bool>(t+1, false));

    for (int i=0;i<n;i++) {
        board[rockWall[i].first][rockWall[i].second] = 1;
    }

    Q.push(make_pair(0,0));
    vis[0][0] = true;

    while (!Q.empty()) {
        int curX = Q.front().first;
        int curY = Q.front().second;
        Q.pop();

        if (curY == t) {
            cout << board[curX][curY];
            return 0;

        }
        int nextX, nextY;

        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                nextX = curX + (i-2);
                nextY = curY + (j-2);

                if (!(0 <= nextX && nextX <= maxX && 0 <= nextY && nextY <= t)) continue;
                if (vis[nextX][nextY] || !board[nextX][nextY]) continue;

                if (nextX - 2 <= curX && curX <= nextX + 2 && nextY - 2 <= curY && curY <= nextY + 2) {
                    Q.push(make_pair(nextX, nextY));
                    vis[nextX][nextY] = true;
                    board[nextX][nextY] += board[curX][curY];
                }
            }
        }
    }

    cout << -1;

    return 0;
}