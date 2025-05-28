#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct subin {
    int location;
    // vector<int> path;
    int time;
};

int main() {
    int n, k;
    cin >> n >> k; //수빈 위치 n / 동생 위치 k
    int l;
    if (n == 0 && k==0) {
        l = 1;
    } else {
        l = (n<k?k:n)*2;
    }
    vector<int> visited(l, -1);
    queue<subin> Q;
    vector<int> result;

    Q.push({n, 0});
    visited[n] = n;

    while (!Q.empty()) {
        subin cur = Q.front();
        Q.pop();

        if (cur.location == k) {
            cout << cur.time << "\n";
            //지나온 길 출력
            int p = cur.location;
            while (true) {
                result.push_back(p);
                if (p == n)
                    break;
                p = visited[p];
            }
            break;
        }

        //x-1로 걷는다
        if (0<=cur.location-1 && cur.location-1<=l && visited[cur.location-1] == -1) {
            visited[cur.location-1]=cur.location;
            Q.push({cur.location-1, cur.time+1});
        }
        //x+1로 걷는다
        if (0<=cur.location+1 && cur.location+1<=l && visited[cur.location+1] == -1) {
            visited[cur.location+1] =cur.location;
            Q.push({cur.location+1, cur.time+1});
        }
        //2*x로 순간이동
        if (0<=cur.location*2 && cur.location*2<=l && visited[cur.location*2] == -1) {
            visited[cur.location*2] =cur.location;
            Q.push({cur.location*2, cur.time+1});
        }
    }

    for (int r=result.size()-1; 0<=r; r--) {
        cout << result[r] << " ";
    }
    return 0;
}