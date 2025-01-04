#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int binary_search(vector<int>& arr, int target) {
//     int low = 0;
//     int high = arr.size();
//
//     while (low < high) {
//         int mid = (low + high) / 2;
//
//         if (arr[mid] < target)
//             low = mid + 1;
//         else
//             high = mid;
//     }
//     return low;
// }

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        long long result = 0;

        for (int j=0; j<n; j++) {
            cin >> a[j];
        }

        for (int k=0; k<m; k++) {
            cin >> b[k];
        }

        sort(b.begin(), b.end());

        for (int j=0; j<n; j++) {
            int low = 0, high = m - 1;
            int mid;

            while (low + 1 < high) {
                mid = (low + high) /2;
                if (b[mid] < a[j])
                    low = mid;
                else
                    high = mid;
            }

            result += (abs(a[j] - b[low]) <= abs(a[j] - b[high])) ? b[low] : b[high];

        }
        cout << result << "\n";
    }
    return 0;
}