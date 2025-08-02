#include<iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> miro(n);
    vector<int> dist(n, -1);
    queue<int> Q;

    for (int i=0; i<n; i++) {
        cin >> miro[i];
    }

    int result = -1;

    // vis[0] = true;
    Q.push(0);
    dist[0] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();


        for (int i = 1; i <= miro[cur]; i++) {
            int next = cur+i;
            if (next >=n)
                break;
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                Q.push(next);
            }

        }
    }

    cout << dist[n-1];

    return 0;
}