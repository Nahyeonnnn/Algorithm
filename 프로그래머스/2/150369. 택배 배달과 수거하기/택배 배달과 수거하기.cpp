#include <string>
#include <vector>
// #include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0; 

    int i=n-1;
    while (0<=i) {
        if (deliveries[i] == 0 && pickups[i] == 0) {
            i--;
            continue;
        }

        int cur_d = cap;
        for (int j = i; 0 < cur_d && 0<=j; j--) {
            if (0 <= deliveries[j] && deliveries[j] <= cur_d) {
                cur_d -= deliveries[j];
                deliveries[j] = 0;
            } else {
                deliveries[j] -= cur_d;
                cur_d = 0;
            }
        }

        int cur_p = cap;
        for (int j = i; 0 < cur_p && 0<=j; j--) {
            if (0 <= pickups[j] && pickups[j] <= cur_p) {
                cur_p -= pickups[j];
                pickups[j] = 0;
            } else {
                pickups[j] -= cur_p;
                cur_p = 0;
            }
        }

        answer += (i+1);
    }

    return answer*2;
}