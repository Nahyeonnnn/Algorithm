#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> dis(n + 1, -1);
    queue<int> Q;
    
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    Q.push(1);
    dis[1] = 0;
    
    while (!Q.empty()) {
        int cur_node = Q.front();
        Q.pop();
        
        for (int i=0; i< adj[cur_node].size(); i++) {
            int next_node = adj[cur_node][i];
            if (dis[next_node] == -1) {
                Q.push(next_node);
                dis[next_node] = dis[cur_node] + 1;
            }
        }
    }
    
    int mx=-1;
    for (int i=1; i<=n; i++) {
        if (dis[i] > mx) {
            mx=dis[i];
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (dis[i] == mx) {
            answer++;
        }
    }
    
    return answer;
}