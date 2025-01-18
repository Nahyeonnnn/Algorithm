#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int total(vector<int> &budget, int max) {
    int n = budget.size();
    int sum = 0;

    for (int i=0; i<n; i++) {
        if (budget[i] <= max)
            sum += budget[i];
        else
            sum += max;
    }

    return sum;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> budget(n, 0);

    for (int i=0; i<n; i++) {
        cin >> budget[i];
    }

    sort(budget.begin(), budget.end());

    cin >> m;

    int l = 0, r = budget[n-1];
    int result = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        int sum = total(budget, mid);

        if (sum <= m) {
            l = mid + 1;
            result = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << result;

    return 0;
}