#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >>n;
    //모든 서브태스크에서 점들의 위치 x와 색깔 y는 0 ≤ x ≤ 105, 1 ≤ y ≤ N를 만족한다.
    vector<vector<int>> list(n+1, vector<int>(0));

    for (int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        list[y].push_back(x);
    }


    for (int i=1; i<=n; i++) {
        sort(list[i].begin(), list[i].end());
    }


    int result = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<list[i].size(); j++) {
            if (j==0) result += abs(list[i][j] - list[i][j+1]);
            else if (j==list[i].size() - 1) result += abs(list[i][j] - list[i][j-1]);
            else {
                int front = abs(list[i][j] - list[i][j-1]);
                int back = abs(list[i][j] - list[i][j+1]);
                result += front > back ? back : front;
            }
        }
    }

    cout << result;
    return 0;
}