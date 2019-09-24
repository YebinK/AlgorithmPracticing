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
		stack<char> s;

		cin >> tmp;

		if (tmp.size() % 2 == 1) { //non-valid Parenthesis String (PS)
			answer.append("NO\n");
			continue;
		}

		for (int j = 0; j < tmp.size(); j++) { //string to stack
			s.push(tmp[j]);
		}

		int right = 0;

		while (!s.empty()) {
			char top = s.top();
			s.pop(); //pop the top
			if (top == ')') right++;
			else right--;

			if (right < 0) { //when "right" goes to negative, it is non-valid PS
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
