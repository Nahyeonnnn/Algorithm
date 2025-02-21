#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;//n: 굴다리의 길이, m:가로등의 개수
    cin >> n >> m;

    vector<int> x(m+2, 0);

    x[0] = 0;
    x[m+1] = n;

    int height = 0;

    for (int i=1; i<=m; i++) {
        cin >> x[i];
    }
    for (int i=1; i<=m+1; i++) {
        if (i==1) {
            height = x[i] - x[i-1];
        } else if (i==m+1) {
            height = x[i] - x[i-1] > height ? x[i] - x[i-1] : height;
        } else {
            int between;
            between = x[i] - x[i-1];
            int new_height = between/2 + between%2;
            height = new_height > height ? new_height : height;
        }
    }

    cout << height;

    return 0;
}