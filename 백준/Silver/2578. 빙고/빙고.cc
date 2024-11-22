#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<int>> &bingo) {
    int count = 0;
    bool flag1 = true, flag2 = true;
    //오른쪽아래 대각선
    for (int i = 0; i < 5; i++) {
        if(bingo[i][i] != 0) {
            flag1 = false;
        }
    }
    if (flag1) count++;
    //왼쪽아래 대각선
    for (int i = 0; i < 5; i++) {
        if(bingo[i][5-i-1] != 0) {
            flag2 = false;
        }
    }
    if (flag2) count++;
    //가로
    for (int i = 0; i < 5; i++) {
        bool rowFlag = true;
        for (int j = 0; j < 5; j++) {
            if(bingo[i][j] != 0) {
                rowFlag = false;
            }
        }
        if (rowFlag) count++;
    }
    //세로
    for (int i = 0; i < 5; i++) {
        bool colFlag = true;
        for (int j = 0; j < 5; j++) {
            if(bingo[j][i] != 0) {
                colFlag = false;
            }
        }
        if (colFlag) count++;
    }

    return count >= 3;
}

void removeNum(vector<vector<int>> &bingo, int curNum) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (bingo[i][j] == curNum) {
                bingo[i][j] = 0;
                return;
            }
        }
    }
}

int main() {
    vector<vector<int>> bingo(5, vector<int>(5, 0));
    vector<vector<int>> bingo2(5, vector<int>(5, 0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo2[i][j];
        }
    }
    int tmp = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp++;
            removeNum(bingo, bingo2[i][j]);
            if (12 <= tmp) {
                if (check(bingo)) {
                    cout << tmp;
                    return 0;
                }
            }
        }
    }


    return 0;
}