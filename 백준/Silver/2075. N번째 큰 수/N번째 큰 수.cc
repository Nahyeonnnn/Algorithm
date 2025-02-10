#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<long long> pq;

    pq.push(1000000001);

    for (int i=0; i<n*n; i++) {
        long long tmp;
        cin >> tmp;
        tmp *= -1;
        if (pq.top() > tmp)
            pq.push(tmp);

        if (pq.size() > n)
            pq.pop();
    }

    cout << -pq.top();

    return 0;
}