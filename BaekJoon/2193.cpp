#include <iostream>
using namespace std;

int main() {

	int n;
	long long count[91][2] = { {0, 0}, {0, 1}, {1, 0} }; //0 count, 1 count

	cin >> n;

	for (int i = 2; i <= n; i++) { //dynamic programming
		count[i][0] = count[i - 1][0] + count[i - 1][1];
		count[i][1] = count[i - 1][0];
	}

	cout << count[n][0] + count[n][1];

	return 0;
}