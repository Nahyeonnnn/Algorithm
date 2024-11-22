#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> hour(k+1);
    vector<int> gain(k+1);

    for (int i=1;i<=k;i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        gain[i] = temp1;
        hour[i] = temp2;
    }

    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

    for (int i=1;i<=k;i++) { //들을 수 있는 수업의 갯수
        for (int j=1;j<=n;j++) { //시간 한도
            if (hour[i]<=j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-hour[i]] + gain[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[k][n];
    return 0;
}