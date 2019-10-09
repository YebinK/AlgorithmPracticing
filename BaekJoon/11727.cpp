#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int sum[1001] = { 0, 1, 3, };

	for (int i = 3; i <= n; i++) {

		sum[i] = sum[i - 2] * 2 + sum[i - 1]; //get number of cases
		sum[i] %= 10007;
	}

	cout << sum[n];


}