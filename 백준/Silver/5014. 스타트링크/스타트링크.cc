#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    //f : 가장 높은 층
    //s : 시작 층
    //g : 스타트링크가 있는 곳
    //u : 위로 u층
    //d : 아래로 d층
    vector<int> floor(f+1, -1);
    queue<int> Q;

    floor[s] = 0;
    Q.push(s);

    while (!Q.empty()) {
        if (floor[g] != -1)
            break;

        int cur_floor = Q.front();
        Q.pop();

        if (1 <= cur_floor + u && cur_floor + u <= f && floor[cur_floor+u] == -1) {
            Q.push(cur_floor+u);
            floor[cur_floor+u] = floor[cur_floor] + 1;
        }
        if (1 <= cur_floor - d && cur_floor - d <= f && floor[cur_floor-d] == -1) {
            Q.push(cur_floor-d);
            floor[cur_floor-d] = floor[cur_floor] + 1;
        }
    }

    if (floor[g] == -1) {
        cout << "use the stairs";
    } else {
        cout << floor[g];
    }

    return 0;
}