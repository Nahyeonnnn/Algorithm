#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >>n;
    vector<pair<int, int>> table(n);
    vector<int> cnt(6,1);

    for (int i=0; i<n; i++) {
        cin >> table[i].first >> table[i].second;
    }

    for (int i=1; i<=5; i++) { //성적 1~5
        int start=0;
        for (int j=0; j<n; j++) {
            if (table[j].first != i && table[j].second != i) {
                start=j+1;
            }
            cnt[i]=max(cnt[i], j-start+1);
        }
    }

    int max_cnt =0;
    int max_g =0;
    for (int g=1; g<=5; g++) {
        if (cnt[g] > max_cnt) {
            max_cnt = cnt[g];
            max_g = g;
        }
    }

    cout << max_cnt << " " << max_g << "\n";

    return 0;
}