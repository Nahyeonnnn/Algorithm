#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    for (int i=0; i<n-1; i++) {
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        result += a*b;
        pq.push(a+b);
    }

    cout << result;

    return 0;
}