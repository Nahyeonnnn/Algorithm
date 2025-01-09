#include <iostream>
#include <math.h>
using namespace std;

void cantor(int n) {
    if (n == 0) {
        cout << "-";
        return;
    }

    // -가 3^n개 있는 문자열이라고 생각
    // 3등분 중 가운데 문자열을 공백으로 바꾼다

    cantor(n-1);
    int power_of_3 = pow(3, n-1);
    for (int i=0; i<power_of_3;i++) {
        cout<< " ";
    }
    cantor(n-1);
}

int main() {

    int n;
    // while (!cin.eof()) {
    //     cin >> n;
    //     cantor(n);
    //     cout << "\n";
    // }
    while (cin >> n) {
        cantor(n);
        cout << "\n";
    }

    return 0;
}