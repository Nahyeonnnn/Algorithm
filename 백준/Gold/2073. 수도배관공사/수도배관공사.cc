#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int d, p;
    cin >> d >> p;

    vector<pair<int, int>> pipes(p); //길이 / 용량
    for (int i=0; i<p; i++) {
        cin >> pipes[i].first >> pipes[i].second;
    }

    vector<int> dp(d+1, 0);
    dp[0] = INT_MAX;

    for (int i=0; i<p; i++) {
        int length = pipes[i].first;
        int yong = pipes[i].second;

        for (int j = d; j >= length; j--) {
            dp[j] = max(dp[j], min(dp[j - length], yong));
        }
    }

    cout << dp[d] << "\n";
    return 0;
}