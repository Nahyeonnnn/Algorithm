#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main() {
    int n, h, w; //원문길이, 세로번짐, 가로번짐
    cin >> n >> h >> w;
    int nw = n*w;

    vector<char> text(n, '?');
    vector<vector<char>> dtext(h, vector<char>(nw));
    for (int i=0; i<h; i++) {
        for (int j=0; j<nw; j++) {
            cin >> dtext[i][j];
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<w; k++) {
                if (dtext[i][j*w+k] != '?') {
                    text[j] = dtext[i][j*w+k];
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << text[i];
    }

    return 0;
}