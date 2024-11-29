#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2147483647

int main() {
    int c, n;

    cin >> c >> n;
    // c: 확보할 호텔의 고객
    // n: 홍보할 수 있는 도시의 개수

    vector<pair<int, int>> city(n);
    vector<int> dp(c+101, INT_MAX);

    for (int i=0; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        city[i] = make_pair(temp1, temp2);
        //비용, 고객 수 쌍으로 저장

        dp[temp2] = temp1;
    }

    dp[0]=0;

    for (int i=1; i<dp.size(); i++) {
        for (int j=0; j<n; j++) {
            if (city[j].second <= i && dp[i-city[j].second] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-city[j].second] + city[j].first);
            }
        }
    }

    int min = dp[c];

    for (int i=c+1; i<dp.size(); i++) {
        if (dp[i] < min)
            min = dp[i];
    }

    cout << min;
}