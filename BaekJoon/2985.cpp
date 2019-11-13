#include <iostream>
using namespace std;

int main() {

	int num1, num2, num3;
	char op[4] = { '+', '-', '*', '/' };
	bool equalIndex = 0; //0 if '=' located after num1, 1 if '=' located before num3
	char opResult = 0;

	cin >> num1 >> num2 >> num3;

	for (int i = 0; i < 4; i++) {
		switch (op[i]) {
			case '+':
				if (num1 == num2 + num3) {
					equalIndex = 0;
					opResult = '+';
					break;
				}
				else if (num1 + num2 == num3) {
					equalIndex = 1;
					opResult = '+';
					break;
				}
			case '-':
				if (num1 == num2 - num3) {
					equalIndex = 0;
					opResult = '-';
					break;
				}
				else if (num1 - num2 == num3) {
					equalIndex = 1;
					opResult = '-';
					break;
				}
			case '*':
				if (num1 == num2 * num3) {
					equalIndex = 0;
					opResult = '*';
					break;
				}
				else if (num1 * num2 == num3) {
					equalIndex = 1;
					opResult = '*';
					break;
				}
			case '/':
				if (num1 == num2 / num3) {
					equalIndex = 0;
					opResult = '/';
					break;
				}
				else if (num1 / num2 == num3) {
					equalIndex = 1;
					opResult = '/';
					break;
				}
				
		}
	}

	if (equalIndex)
		cout << num1 << opResult << num2 << '=' << num3;
	else
		cout << num1 << '=' << num2 << opResult << num3;


	return 0;
}