#include <iostream>
#include <math.h>
using namespace std;
//멍멍이 쓰다듬기
int main() {
    int x, y; //원숭이 키 x / 멍멍이 키 y
    cin >> x >> y;
    int difference = y-x;
    if (difference == 0 || difference == 1) {
        cout << difference;
        return 0;
    }

    // int n=sqrt(difference);
    //여기서 시간초과인듯
    // while (n*(n+1) < difference) {
    //     n++;
    // }

    long long n = (-1 + sqrt(1 + 4LL * difference)) / 2;
    if (n*(n+1) < difference) {
        n++;
    }

   if (difference <= n*n) {
        cout << 2*n -1;
    } else {
        cout << 2*n;
    }

    return 0;
}