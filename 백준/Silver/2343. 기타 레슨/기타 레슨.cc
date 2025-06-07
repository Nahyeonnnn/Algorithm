#include <iostream>
#include <vector>
using namespace std;

bool is_possible(int blu_size, vector<int> &lecture, int m) {
    int i;
    int blu_cnt=1;
    int size=0;
    for (i=0; i<lecture.size(); i++) {
        if (size + lecture[i] > blu_size) {
            blu_cnt++;
            size=lecture[i];
        } else {
            size += lecture[i];
        }
    }

    if (blu_cnt > m)
        return false;
    return true;
}

int main() {
    int n, m;//강의의 수 N, 블루레이 M개
    cin >> n >> m;
    vector<int> lecture(n,0);
    int max_l = 0;
    int total_l = 0;
    for (int i=0; i<n; i++) {
        cin >> lecture[i];
        total_l+= lecture[i];
        if (max_l < lecture[i]) max_l = lecture[i];
    }

    int l = max_l;
    int r = total_l;
    int possible=total_l;

    while (l <= r) {
        int mid = (l + r)/2;

        if (is_possible(mid, lecture, m)) {
            r = mid-1;
            possible = possible < mid ? possible : mid;
        }
        else
            l = mid+1;
    }

    cout << possible;


    return 0;
}