#include <iostream>
using namespace std;

#define max_size 101
#define mod 1000000000

int main() {

	int n;
	int count[max_size][10];

	cin >> n;

	count[1][0] = 0; //initialization
	for (int i = 1; i <= 9; i++) {
		count[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				count[i][j] = count[i - 1][j + 1];
				continue;
			}
			if (j == 9){
				count[i][j] = count[i - 1][j - 1];
				continue;
			}
			count[i][j] = count[i - 1][j - 1] + count[i - 1][j + 1];
			count[i][j] %= mod;
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += count[n][i];
		sum %= mod;
	}

	cout << sum;

	return 0;
}