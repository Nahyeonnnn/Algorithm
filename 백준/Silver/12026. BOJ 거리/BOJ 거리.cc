#include<iostream>
#include<vector>
#include <math.h>
#include<queue>
#include <limits.h>
using namespace std;

char next_block(const char b);

int main() {
    queue<int> Q;
    int n;
    cin >> n;
    vector<double> energy(n+1, -1);
    vector<char> blocks(n+1);

    for (int i=1;i<=n;i++) {
        cin >> blocks[i];
    }

    Q.push(1);
    energy[1] = 0;

    while (!Q.empty()) {
        int cur_block_index = Q.front();
        Q.pop();

        char next_block_char = next_block(blocks[cur_block_index]);
        int i = cur_block_index;
        while (i < n) {
            i++;
            double next_energy = energy[cur_block_index] + pow(i - cur_block_index, 2);
            if (blocks[i] == next_block_char && (energy[i] == -1 || next_energy < energy[i])) {
                Q.push(i);
                energy[i] = next_energy;
            }
        }
    }

    cout << energy[n];

    return 0;
}

char next_block(const char b) {
    switch (b) {
        case 'B':
            return 'O';
        case 'O':
            return 'J';
        case 'J':
            return 'B';
        default:
            return -1;
    }
}