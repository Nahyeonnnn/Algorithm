#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void pre_to_stack(vector<int> &list, stack<int> &stack, int start, int end) {
    if (start > end) {
        return;
    }
    stack.push(list[start]);

    int right_start = start + 1;
    while (right_start <= end && list[right_start] < list[start]) {
        right_start++;
    }

    pre_to_stack(list, stack, right_start, end);
    pre_to_stack(list, stack, start + 1, right_start - 1);
}

int main() {
    //전위 순회
    //     1
    // 2      3
    //후위 순회
    //     3
    // 1       2
    //스택에 넣을 땐
    //     1
    // 3       2

    int node;
    vector<int> list;
    stack<int> stack;
    
    while (cin >> node) {
        list.push_back(node);
    }

    // list = {50, 30, 24, 5, 28, 45, 98, 52, 60};

    pre_to_stack(list, stack, 0, list.size() - 1);

    while (!stack.empty()) {
        cout << stack.top() << "\n";
        stack.pop();
    }

    return 0;
}