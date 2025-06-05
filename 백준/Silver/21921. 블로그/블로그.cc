#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,x;//블로그 시작하고 지난 일수 N, 기간 X
    cin >> n >> x;
    vector<long> log(n);
    vector<long> visitors(n-x+1, 0);
    for (int i=0; i<n; i++) {
        cin >> log[i];
    }

    long max_visitors=0;

    for (int i=0;i<x;i++) {
        max_visitors+=log[i];
    }

    visitors[0] = max_visitors;

    for (int i=x; i<n; i++) {
        visitors[i-x+1] = visitors[i-x] - log[i-x] + log[i];
        if (visitors[i-x+1] > max_visitors)
            max_visitors = visitors[i-x+1];
    }

    if (max_visitors == 0) {
        cout << "SAD";
        return 0;
    }

    cout << max_visitors << "\n";

    int cnt = 0;
    for (auto vis_cnt : visitors) {
        if (max_visitors == vis_cnt)
            cnt++;
    }

    cout << cnt;

    return 0;
}