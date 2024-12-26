#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rope(n);
    for (int i=0; i<n; i++) {
        cin >> rope[i];
    }

    // 작은 로프를 빼고 나머지 줄들을 선택했을 때 최대 중량이 더 높은 경우?
    // 2 9 9 -> 2를 빼고 하는게 낫긴 함

    sort(rope.begin(), rope.end());

    int max_w = rope[0] * n;

    for (int i=1; i<n; i++) {
        int tmp = rope[i] * (n-i);
        if (max_w < tmp)
            max_w = tmp;
    }

    cout << max_w;

    return 0;
}