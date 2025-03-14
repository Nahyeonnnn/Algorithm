#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; //배열 A의 크기 N, 배열 B의 크기 M
    vector<int> arr(n+m);

    int i;
    for (i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int j=0; j<m; j++) {
        cin >> arr[i];
        i++;
    }

    sort(arr.begin(), arr.end());

    for (auto e : arr) {
        cout << e << " ";
    }

    return 0;
}