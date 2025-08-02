#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<long long>> dp(n+1, vector<long long>(11, 0));

    for (int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            if (j==0)
                dp[i][j] = 0 + dp[i-1][j+1];
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000L;
        }
    }

    unsigned long long result=0;
    for (int i=0; i<=9; i++) {
        result += dp[n][i];
    }

    cout << result % 1000000000L;

    return 0;
}