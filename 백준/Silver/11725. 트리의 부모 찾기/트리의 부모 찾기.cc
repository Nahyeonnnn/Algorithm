#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    bool linked;
    int parent;
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nodes(n+1);
    vector<node> parent(n+1);
    queue<int> Q;

    for (int i=0; i<n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        nodes[n1].push_back(n2);
        nodes[n2].push_back(n1);
    }

    parent[1] = {true,1};
    for (int i=2; i<=n; i++) {
        parent[i] = {false, i};
    }

    Q.push(1);
    while (!Q.empty()) {
        int cur_node = Q.front();
        Q.pop();

        for (int linked_node : nodes[cur_node]) {
            if (!parent[linked_node].linked) {
                parent[linked_node].linked = true;
                parent[linked_node].parent = cur_node;
                Q.push(linked_node);
            }
        }
    }

    for (int i=2; i<=n; i++) {
        cout << parent[i].parent<<"\n";
    }

    return 0;
}