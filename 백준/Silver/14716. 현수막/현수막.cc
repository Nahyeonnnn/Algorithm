#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//상하좌우 대각선
int x_next[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int y_next[8] = {1, -1, 0, 0, 1, -1, -1, 1};

struct pixel {
    int i;
    int j;
};

void bfs(int i, int j, vector<vector<int> > &banner ,vector<vector<bool> > &visited, const int m, int n) {
    queue<pixel> Q;

    visited[i][j] = true;
    pixel p = {i, j};
    Q.push(p);

    while (!Q.empty()) {
        int i = Q.front().i;
        int j = Q.front().j;
        Q.pop();

        for (int k=0; k<8; k++) {
            int i_next = i + x_next[k];
            int j_next = j + y_next[k];

            if (i_next < 0 || m <= i_next || j_next < 0 || n <= j_next)
                continue;

            if (visited[i_next][j_next] || banner[i_next][j_next] == 0)
                continue;

            visited[i_next][j_next] = true;
            pixel next = {i_next, j_next};
            Q.push(next);
        }
    }
}

int main() {
    // 1이 상, 하, 좌, 우, 대각선으로 인접하면 하나의 글자로 생각
    int m, n;
    int cnt = 0;
    cin >> m >> n;
    vector<vector<int> > banner(m, vector<int>(n));
    vector<vector<bool> > visited(m, vector<bool>(n, false));

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> banner[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (banner[i][j] == 1 && visited[i][j] == false) {
                bfs(i,j,banner, visited, m, n);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}