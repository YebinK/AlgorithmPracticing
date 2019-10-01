#include <iostream>
#include <stack>
using namespace std;

int main() {

	int n, cmd, result = 0;
	stack<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd != 0)
			s.push(cmd);
		else
			s.pop();
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	cout << result;

	return 0;
}