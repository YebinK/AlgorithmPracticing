#include <iostream>
#include <stack>
using namespace std;

int main() {

	int n, j = 0;
	string cmd[10000] = {"", };
	int push[10000] = { 0, };
	stack<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd[i]; //명령어와 숫자 모두 string type
		if (cmd[i] == "push") {
			cin >> push[j];
			j++;
		}
	}

	j = 0;

	for (int i = 0; i < n; i++) {
		if (cmd[i] == "push") {
			s.push(push[j]);
			j++;
		}
		else if (cmd[i] == "pop") {
			if (s.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cmd[i] == "size") {
			cout << s.size() << "\n";
		}
		else if (cmd[i] == "empty") {
			if (s.empty())
				cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else { //top
			if (s.empty()) {
				cout << "-1" << "\n";
			}
			else cout << s.top() << "\n";
		}
	}


	return 0;
}