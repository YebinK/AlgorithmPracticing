#include <iostream>
#include <algorithm>
using namespace std;

#define max_size 10001

int main() {
	
	int n;
	int wine[max_size], dp[max_size];

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	dp[0] = 0; //initialization
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	for (int i = 3; i <= n; i++) { //get max
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]); //if wine[i] included
		dp[i] = max(dp[i], dp[i - 1]); //if wine[i] not included
	}

	cout << dp[n];
	
	return 0;
}
