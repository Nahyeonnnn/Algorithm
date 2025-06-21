#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long result = 0;

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    //(50,500,000 - 101) * 101

    for (int i=0; i<n-1; i++) {
        long long a, b;
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