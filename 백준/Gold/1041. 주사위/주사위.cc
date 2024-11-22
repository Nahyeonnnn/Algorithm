#include <iostream>
#include <vector>
using namespace std;

//3면이 보이는 조합
vector<vector<int>> threeFace =
{
   {0,1,2},
    {0,2,4},
    {0,1,3},
    {0,3,4},
    {1,2,5},
    {1,3,5},
    {3,4,5},
    {2,4,5}
};

//2면이 보이는 조합
vector<vector<int>> twoFace =
{
    {0,1},
    {0,2},
    {0,3},
    {0,4},
    {1,2},
    {1,3},
    {1,5},
    {2,4},
    {2,5},
    {3,4},
    {3,5},
    {4,5}
};


int main() {
    long n;
    vector<int> dice(6);

    cin >> n;

    for(int i=0;i<6;i++) {
        cin >> dice[i];
    }

    //n이 1인경우?
    if (n == 1) {
        int total = 0;
        int maxFace = dice[0];
        for (int i=0; i<6; i++) {
            total += dice[i];
            if (maxFace < dice[i]) {
                maxFace = dice[i];
            }
        }
        cout << total - maxFace;
        return 0;
    }

    long minThreeFace, minTwoFace, minOneFace;

    //3면 최솟값
    minThreeFace = dice[threeFace[0][0]] +  dice[threeFace[0][1]] + dice[threeFace[0][2]];
    for (int i=0; i < threeFace.size(); i++) {
        long tmp = dice[threeFace[i][0]] +  dice[threeFace[i][1]] + dice[threeFace[i][2]];
        if (minThreeFace > tmp) {
            minThreeFace = tmp;
        }
    }

    //2면 최솟값
    minTwoFace = dice[twoFace[0][0]] + dice[twoFace[0][1]];
    for (int i=0; i<twoFace.size();i++) {
        long tmp = dice[twoFace[i][0]] + dice[twoFace[i][1]];
        if (minTwoFace > tmp) {
            minTwoFace = tmp;
        }
    }

    //1면 최솟값
    minOneFace = dice[0];
    for (int i=0;i<6;i++) {
        if (minOneFace > dice[i]) {
            minOneFace = dice[i];
        }
    }

    //주사위 면의 최솟값 계산
    //3면 -> 4개
    //2면 -> 4(2N-3)
    //1면 -> (5N - 6)(N - 2) = 5N^2 - 16N + 12
    long total = 4 * minThreeFace + 4*(2*n-3)*minTwoFace + (5*n-6)*(n-2)*minOneFace;

    cout<<total;

    return 0;
}