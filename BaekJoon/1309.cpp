#include <iostream>
using namespace std;

#define max_size 100001

int main() {

	int n; // cage size == (n x 2)
	long long cage[max_size] = {1, 3, };

	cin >> n;

	for (int i = 2; i <= n; i++) {
		cage[i] = cage[i - 1] * 2 + cage[i - 2];
		cage[i] %= 9901;
	}
	
	cout << cage[n];

	return 0;
}