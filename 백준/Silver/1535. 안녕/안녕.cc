#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    //최대 기쁨

    vector<int> health(n);
    vector<int> happy(n);
    vector<int> dp(101, 0);

    for (int i=0;i<n;i++) cin>>health[i];
    for (int i=0;i<n;i++) cin>>happy[i];

    for (int i=0; i<n; i++) {
        for (int j = 100; j > 0; j--) {
            if (j > health[i]) {
                dp[j] = max(dp[j], dp[j - health[i]] + happy[i]);
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= 100; j++) {
        result = max(result, dp[j]);
    }

    cout << result << "\n";

    return 0;
}