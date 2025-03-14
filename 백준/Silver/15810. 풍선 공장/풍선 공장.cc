#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long binary_search(const vector<long long> &time, long long start, long long end, long long goal) {
    long long min_result = end;
    while (start <= end) {
        long long mid = (start + end)/2;
        int balloon=0;
        for (auto m:time) {
            balloon+=mid/m;
        }
        if (balloon<goal) {
            start = mid + 1;
        } else {
            min_result = min(min_result, mid);
            end = mid - 1;
        }
    }
    return min_result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; //스태프의 수 N과 풍선의 수 M
    cin >> n >> m;
    vector<long long> time(n);

    for (int i=0; i<n; i++) {
        cin >> time[i];
    }
    sort(time.begin(), time.end());
    cout << binary_search(time, 1, m*time[0], m);

    return 0;
}