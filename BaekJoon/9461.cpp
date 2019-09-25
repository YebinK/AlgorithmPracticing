#include <iostream>
using namespace std;

int main() {

	int n; //number of test case
	long long ps[101] = { 0, 1, 1, 1, 2, 2, }; //padovan sequence
	long long answer[101] = { 0, }; //answer set

	cin >> n;

	for (int i = 6; i < 101; i++) { //pattern of padovan sequence
		ps[i] = ps[i - 1] + ps[i - 5];
	}

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		answer[i] = ps[input];
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] <<'\n';
	}

	return 0;
}