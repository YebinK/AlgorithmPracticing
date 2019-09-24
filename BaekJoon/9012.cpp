#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	int n; //#test case
	string answer;

	cin >> n;
	
	for (int i = 0; i < n; i++) {

		string tmp;
		cin >> tmp;

		stack<char> s;

		for (int j = 0; j < tmp.size(); j++) { //string to stack
			s.push(tmp[j]);
		}

		if (s.size() % 2 == 1) { //non-valid Parenthesis String
			answer.append("NO\n");
			continue;
		}

		int right = 0;

		while (!s.empty()) {
			char top = s.top();
			s.pop(); //pop the top
			if (top == ')') right++;
			else right--;

			if (right < 0) {
				answer.append("NO\n");
				break;
			}
		}

		if (right > 0)
			answer.append("NO\n");
		else if (right == 0)
			answer.append("YES\n");

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	
	return 0;
}