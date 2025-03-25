#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

struct Edge {
    int v1, v2, cost; //정점1, 정점2, 비용
};

auto compare = [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; //작은거
};

vector<int> dijkstra(int &v, vector<vector<Edge>> &adj, int start) {
    vector<int> dist(v+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    dist[start] = 0;
    pq.push(make_pair(start, dist[start]));

    while (!pq.empty()) {
        int cur_v, cur_cost;
        tie(cur_v, cur_cost) = pq.top(); // (정점, 비용) 순
        pq.pop();

        for (auto e : adj[cur_v]) {
            int next_v = e.v2;
            if (dist[next_v] > cur_cost + e.cost) {
                dist[next_v] = cur_cost + e.cost;
                pq.push(make_pair(next_v, dist[next_v]));
            }
        }
    }

    return dist;
}

int main() {
    int v, e, p; //정점의 개수, 간선의 개수, 건우 위치
    cin >> v >> e >> p;
    vector<vector<Edge>> adj(v+1, vector<Edge>());//인접 간선 저장
    vector<int> dist1(v+1, 0);
    vector<int> dist2(v+1, 0);

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({a,b,c});
        adj[b].push_back({b,a,c});
    }

    dist1 = dijkstra(v, adj, 1);
    dist2 = dijkstra(v, adj, p);

    if (dist1[v] < dist1[p] + dist2[v]) {
        cout << "GOOD BYE";
        return 0;
    }

    cout << "SAVE HIM";

    return 0;
}