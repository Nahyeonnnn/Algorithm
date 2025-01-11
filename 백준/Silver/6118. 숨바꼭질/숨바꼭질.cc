#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> edge(n+1);
    vector<int> distance(n+1, -1); //거리 저장
    vector<bool> visited(n+1, false);
    queue<int> Q;

    for (int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    Q.push(1);
    distance[1] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;

        for (int next : edge[cur]) {
            if (distance[next] == -1) {
                Q.push(next);
                distance[next] = distance[cur] + 1;
            }
        }



    }

    int max_index = 1;

    for (int i=1; i<=n; i++) {
        if (distance[max_index] < distance[i])
            max_index = i;
    }

    int max_count = 0;
    for (int i=1; i<=n; i++) {
        if (distance[max_index] == distance[i])
            max_count++;
    }

    cout << max_index << " " << distance[max_index] << " " << max_count;


    return 0;
}