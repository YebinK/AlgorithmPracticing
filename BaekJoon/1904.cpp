#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	long long* arr = new long long[n + 1] {0, 1, 2, };

	for (int i = 3; i <= n; i++) {
		if (n < 3) break;
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746;
	}

	cout << arr[n];

	return 0;
}