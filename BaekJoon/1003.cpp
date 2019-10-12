#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define max_size 41

int main() {

	int t; //testcase
	long long dp[max_size][2]; //# of calling 0, # of calling 1

	vector<pair<long long, long long>> answer;

	dp[0][0] = 1; //initialization
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i < max_size; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	cin >> t;

	for (int i = 0; i < t; i++) {
		int number;
		cin >> number;

		answer.push_back(make_pair(dp[number][0], dp[number][1]));
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << endl;
	}

	return 0;
}