#include <iostream>
#include <string>
using namespace std;

bool is_good_seq(string &r) {
    int length = r.length();
    for (int i = 1; i <= length / 2; i++) {
        string a = r.substr(length - i, i);
        string b = r.substr(length - 2 * i, i);
        if (a == b)
            return false;
    }
    return true;
}

bool found = false;

void make_good_seq(string &r, int n) {
    if (found) return;

    if (r.length() == n) {
        cout << r << "\n";
        found = true;
        return;
    }

    for (int j = 1; j <= 3; j++) {
        r.push_back('0' + j);

        if (is_good_seq(r)) {
            make_good_seq(r, n);
        }

        r.pop_back(); 
    }
}

int main() {
    int n;
    cin >> n;
    string result;
    make_good_seq(result, n);
    return 0;
}
