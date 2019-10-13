#include <iostream>
#include <algorithm>
using namespace std;

#define max_stairs 301

int main() {

	int n; //number of stairs
	int stair[max_stairs], DP[max_stairs];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	DP[0] = stair[0]; //initialize DP
	if (n >= 1) DP[1] = DP[0] + stair[1];
	if (n >= 2) DP[2] = max(DP[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) {
		DP[i] = max(DP[i - 2] + stair[i], DP[i - 3] + stair[i - 1] + stair[i]);
	}


	cout << DP[n - 1];

	return 0;
}