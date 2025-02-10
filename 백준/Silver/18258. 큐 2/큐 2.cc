#include<iostream>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	queue <int> q;
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			int j;
			cin >> j;
			q.push(j);
		}
		else if (s == "pop") {
			if (q.empty()) { cout << "-1\n"; }
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty()) { cout << "1\n"; }
			else { cout << "0\n"; }
		}
		else if (s == "front") {
			if (q.empty()) { cout << "-1\n"; }
			else { cout << q.front() << "\n"; }
		}
		else if (s == "back") {
			if (q.empty()) { cout << "-1\n"; }
			else { cout << q.back() << "\n"; }
		}
	}
	return 0;
}