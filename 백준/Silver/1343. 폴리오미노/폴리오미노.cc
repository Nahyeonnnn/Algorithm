#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string board;
    cin >> board;

    int length = board.size();

    int countX = 0;
    vector<char> result;

    for (int i=0; i<length; i++) {
        if (board[i] == 'X') {
            countX++;
        }
        else if (board[i] == '.') {
            if (countX % 2 != 0) {
                cout << -1;
                return 0;
            }
            while (countX != 0) {
                if (4 <= countX) {
                    // board.replace(i - countX, 4, "AAAA");
                    result.insert(result.end(), {'A','A','A','A'});
                    // cout << "AAAA";
                    countX -= 4;
                } else {
                    // board.replace(i-countX, 2, "BB");
                    result.insert(result.end(), {'B','B'});
                    // cout << "BB";
                    countX -= 2;
                }
            }
            result.insert(result.end(), '.');
            // cout << ".";
        }

    }
    if (countX > 0) {
        if (countX % 2 != 0) {
            cout << -1;
            return 0;
        }
        while (countX != 0) {
            if (4 <= countX) {
                // board.replace(i - countX + 1, 4, "AAAA");
                // cout << "AAAA";
                result.insert(result.end(), {'A','A','A','A'});
                countX -= 4;
            } else {
                // board.replace(i - countX + 1, 2, "BB");
                result.insert(result.end(), {'B','B'});
                // cout << "BB";
                countX -= 2;
            }
        }
    }

    for (int i=0;i<length;i++) {
        cout << result[i];
    }

    return 0;
}