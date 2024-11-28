#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, result = 0;

    cin >> n;

    vector<int> level(n);

    for (int i=0; i<n; i++) {
        cin >> level[i];
    }

    for (int i=n-2; 0 <= i; i--) {
        if (level[i] >= level[i+1]) {
            result += level[i] - (level[i+1] - 1);
            level[i] = level[i+1] - 1;
        }
    }

    cout << result;
}