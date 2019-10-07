#include <iostream>
using namespace std;

int main() {

	int n, result, sum = 0, count = 0; //sum: sum of coins, count: coin count
	int coin[10];
	cin >> n >> result;

	for (int i = n - 1; i >= 0; i--) { //get coin array (desc order)
		cin >> coin[i];
	}

	for (int i = 0; i < n; i++) {
		if (sum == coin[i]) break; 
		if (sum + coin[i] > result) continue;

		while (sum + coin[i] <= result) {
			sum += coin[i];
			count++;
		}

	}

	cout << count;

	return 0;
}