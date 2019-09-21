#include <iostream>
using namespace std;

int main() {

	int n;
	long long fibo[91] = { 0, 1, 0, };

	cin >> n;

	if (n <= 1) {
		cout << fibo[n];
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n];

	return 0;
}
