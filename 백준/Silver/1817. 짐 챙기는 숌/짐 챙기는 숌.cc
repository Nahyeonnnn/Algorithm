#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;//책 개수 N, 박스에 넣을 수 있는 최대 무게 M
    cin >> n >> m;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> book(n);
    int cnt = 1; //박스 개수
    int box = 0;
    for (int i=0; i<n; i++) {
        cin >> book[i];
    }

    for (int i=0; i<n; i++) {
        if (box + book[i] <= m) {
            box += book[i];
        } else {
            cnt ++;
            box = book[i];
        }
    }

    cout << cnt;


    return 0;
}