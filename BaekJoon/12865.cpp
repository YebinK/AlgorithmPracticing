#include <iostream>
#include <algorithm>
using namespace std;

int n, maxW;
int dp[101][100001];
int item[101][2]; //weight-value

int main() {

	cin >> n >> maxW; //number of items, max weight

	for (int i = 1; i <= n; i++) { //get input
		cin >> item[i][0] >> item[i][1];
	}

	int curW = 0; //current weight
	for (int i = 1; i <= n; i++) {
		for (int curW = 0; curW <= maxW; curW++) {
			
			if (curW + item[i][0] <= maxW) //if available
				dp[i][curW] = max(dp[i - 1][curW], dp[i - 1][curW + item[i][0]] + item[i][1]);
			else
				dp[i][curW] = dp[i - 1][curW];
		}
	}

	cout << dp[n][0]; //get max

	return 0;
}