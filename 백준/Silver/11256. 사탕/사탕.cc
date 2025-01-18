#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int j, n;//사탕의 개수 j와 상자의 개수 n
        cin >> j >> n;

        vector<int> box(n, 0);

        for (int k=0;k<n;k++) {
            int x, y;
            cin >> x >> y;
            box[k] = x*y;
        }

        sort(box.begin(), box.end(), greater<int>());

        int cnt, candy = 0;
        for (cnt=0; cnt < n; cnt++) {
            candy += box[cnt];
            if (candy >= j) break;
        }

        cnt++;
        cout << cnt << "\n";
    }

    return 0;
}