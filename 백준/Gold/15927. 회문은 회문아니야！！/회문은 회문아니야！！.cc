#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(int start, int end, string &p) {
    int l=start, r=end;
    while (l < r) {
        if (p[l] != p[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool is_same_string(int start, int end, string &p) {
    char z = p[start];
    while (start < end) {
        if (p[end] != z) {
            return false;
        }
        end--;
    }
    return true;
}

int main() {
    string p;
    cin >> p;

    if (is_same_string(0, p.size()-1, p)) {
        cout << -1;
        return 0;
    }

    if (is_palindrome(0, p.size()-1, p)) {
        cout << p.size()-1;
        return 0;
    }



    cout << p.size();


    return 0;
}