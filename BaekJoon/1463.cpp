#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	long long n;

	cin >> n;

	if (n <= 1) {
		cout << 0;
		return 0;
	}

	long long* result = new long long[n + 2]{ 0, 0, 1, 1 }; //result[2] = 1, result[3] = 1

	for (int i = 4; i <= n; i++) {

		if (i % 3 == 0) {
			result[i] = min(result[i - 1] + 1, result[i / 3] + 1);
			continue;
		}
		if (i % 2 == 0) {
			result[i] = min(result[i - 1] + 1, result[i / 2] + 1);
			continue;
		}
		result[i] = result[i - 1] + 1;
	}

	cout << result[n];

	return 0;
}