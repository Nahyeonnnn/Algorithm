#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n; //트리의 노드 개수
    vector<int> tree(n);
    vector<vector<int>> link(n);
    int root;
    for (int i=0; i<n; i++) {
        cin >> tree[i];
        if (tree[i] != -1) {
            link[tree[i]].push_back(i);
        }
    }

    int remove;
    cin >> remove;

    if (remove == -1) {
        cout << 0 <<"\n";
        return 0;
    }

    vector<bool> deleted (n, false);
    //mark deleted
    queue<int> Q;
    Q.push(remove);
    deleted[remove] = true;

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        for (int child : link[current]) {
            if (!deleted[child]) {
                deleted[child]=true;
                Q.push(child);
            }
        }
    }

    int leaf = 0;

    for (int i=0; i<n; i++) {
        if (deleted[i]) continue;

        bool isLeaf = true;
        for (int child : link[i]) {
            if (!deleted[child]) {
                isLeaf = false;
                break;
            }
        }

        if (isLeaf) leaf++;
    }


    cout << leaf;

    return 0;
}