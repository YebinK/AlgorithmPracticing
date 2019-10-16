#include <iostream>
#include <algorithm>
using namespace std;

#define max_size 10001

int main() {
	
	int n;
	int wine[max_size], dp[max_size];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	dp[0] = wine[0];					//initialization
	dp[1] = dp[0] + wine[1];
	dp[2] = max(dp[1], dp[0] + dp[2]);

	for (int i = 3; i < n; i++) { //get max
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
	}

	sort(dp, dp + n);
	cout << dp[n - 1];
	
	return 0;
}