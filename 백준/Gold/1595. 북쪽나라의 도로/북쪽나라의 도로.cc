#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct linked_city {
    int cur_c;
    int next_c;
    int dist;
};

int D(int start, vector<vector<int>> &dist, vector<vector<linked_city>> &city) {
    queue<int> Q;
    dist[start][start] = 0;
    Q.push(start);

    while (!Q.empty()) {
        int cur_city = Q.front();
        Q.pop();

        for (int i=0; i<city[cur_city].size(); i++) {
            linked_city next_city = city[cur_city][i];

            if (dist[start][next_city.next_c] == -1 && dist[start][next_city.cur_c] != -1) {
                dist[start][next_city.next_c] = dist[start][next_city.cur_c] + next_city.dist;
                Q.push(next_city.next_c);
            }
        }
    }

    int max_dist=0;
    for (int i=0; i<dist[start].size(); i++) {
        if (max_dist<dist[start][i])
            max_dist = dist[start][i];
    }

    return max_dist;
}

int main() {
    // freopen("/Users/nahyeon/algorithm/input_1595.txt", "r", stdin);  //임시 테스트용


    int c1,c2,d;
    int max_city = 0;
    vector<vector<linked_city>> city(10000);
    while (cin >> c1 >> c2 >> d) {
        int large_city = c1 > c2 ? c1: c2;
        if (max_city < large_city)
            max_city = large_city;

        city[c1].push_back({c1, c2, d});
        city[c2].push_back({c2, c1, d});
    }
    vector<vector<int>> dist(max_city+1, vector<int>(max_city+1, -1));

    int max_dist=0;
    for (int i=1; i<=max_city; i++) {
        int result = D(i, dist, city);
        if (max_dist < result)
            max_dist = result;

    }

    cout << max_dist;
    return 0;
}
