#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start_node, vector<vector<int>> &computers, int n, vector<bool> &vis) {
    queue<int> Q;
    Q.push(start_node);
    vis[start_node] = true;
    
    while (!Q.empty()) {
        int cur_node = Q.front();
        Q.pop();
        
        for (int i=0; i<n; i++) {
            if (vis[i] == false && computers[cur_node][i] == 1) {
                Q.push(i);
                vis[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> vis(n, false);
    
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            bfs(i, computers, n, vis);
            answer++;
        }
    }
    
    return answer;
}