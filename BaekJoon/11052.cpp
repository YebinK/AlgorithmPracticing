#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	int card[1001];
	int dp[10001];

	cin >> n;

	for (int i = 1; i <= n; i++) { //get input, initialization
		cin >> card[i];
		dp[i - 1] = 0;
	}

	for (int i = 1; i <= n; i++) { //get max cost
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i], dp[j] + card[i - j]);
		}
	}

	cout << dp[n];

	return 0;
}