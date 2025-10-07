#include <string>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <cstdlib>

using namespace std;
/**
n x m 격자에서
(x,y) --> (r,c)
1. 격자 바깥 xx
2. 총 거리 k, 중복 방문 가능
3. 탈출 경로 문자열 사전순 가장 빠른 경로
*/

struct node {
    int x;
    int y;
    string path;
};

char char_next[4] = {'u', 'r', 'l', 'd'};
int x_next[4] = {-1, 0, 0, 1};
int y_next[4] = {0, 1, -1, 0};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    // string answer = "";
    stack<node> st;
    set<string> path_list;

    int dis = abs(x - r) + abs(y - c);
    
    if ((k-dis)%2 != 0)
        return "impossible";

    st.push({x, y, ""});

    while(!st.empty()) {
        node cur = st.top();
        st.pop();
        
        if (cur.path.size() == k) {
            if (cur.x == r && cur.y == c) {
                return cur.path;
            }
            continue;
        }
        
        int cur_dis = abs(cur.x - r) + abs(cur.y - c);
        int depth = cur.path.size();
        if (k - depth < cur_dis || (k - depth - cur_dis) %2 != 0) {
            continue;
        }
        
        for (int i=0; i<4; i++) {
            int nx = cur.x + x_next[i];
            int ny = cur.y + y_next[i];
            string npath = cur.path + char_next[i];
            if (0 < nx&&nx <= n && 0 < ny&&ny <= m) {
                st.push({nx, ny, npath});
            }
        }
    }

    return "impossible";
}