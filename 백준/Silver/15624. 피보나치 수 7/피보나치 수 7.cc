#include<iostream>
#include<vector>
using namespace std;

int main() {

    // 0 1 1 2 3 5 8 13 ....
    // Fn = Fn-1 + Fn-2

    int n;
    cin >> n;

    vector<int> fibo(n+1);

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2;i<=n;i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        if (fibo[i] > 1000000007) {
            fibo[i] = fibo[i] % 1000000007;
        }
    }

    cout << fibo[n] % 1000000007;

    return 0;
}