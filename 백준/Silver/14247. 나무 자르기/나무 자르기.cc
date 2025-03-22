#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    // vector<int> H(n);
    // vector<int> A(n);
    // vector<vector<int>> namu(2, vector<int>(n)); //h, a
    vector<pair<int, int>> namu2(n, make_pair(0,0)); //h, a
    long long result = 0;

    for (int i=0; i<n; i++) {
        // cin >> namu[0][i];
        cin >> namu2[i].first;
    }
    for (int i=0; i<n; i++) {
        // cin >> namu[1][i];
        cin >> namu2[i].second;
    }

    sort(namu2.begin(), namu2.end(), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
    for (int i=0; i<n; i++) {
        result += namu2[i].first + i*namu2[i].second;
    }

    cout << result;

    return 0;
}