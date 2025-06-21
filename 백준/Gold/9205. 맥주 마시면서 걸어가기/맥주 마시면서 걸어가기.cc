#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct coord {
    int x;
    int y;
};

int dist(coord a, coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<coord> loc(n+2);
        vector<bool> vis(n+2, false);
        for (int j=0; j<n+2; j++) {
            int a,b;
            cin >> a >> b;
            loc[j]= {a, b};
        }
        queue<coord> Q;
        Q.push(loc[0]);
        vis[0]=true;

        while (!Q.empty()) {
            coord cur = Q.front();
            Q.pop();

            for (int k=0; k<n+2; k++) {
                if (!vis[k] && dist(cur, loc[k])<=1000) {
                    Q.push(loc[k]);
                    vis[k]=true;
                }
            }

        }

        if (vis[n+1])
            cout << "happy\n";
        else
            cout <<"sad\n";
    }

    return 0;
}