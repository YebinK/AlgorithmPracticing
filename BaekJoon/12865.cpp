/*

//--by recursion--

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, maxW;
int dp[101][100001];
vector<pair<int, int>> item; //weight-value

int ks(int i, int w) { //knapsack algorithm

	if (i == n) return 0;
	if (dp[i][w] > 0) return dp[i][w];

	int v1 = 0;
	if (w + item[i].first <= maxW) //if available
		v1 = item[i].second + ks(i + 1, w + item[i].first); //include i
	int v2 = ks(i + 1, w); //not include i

	dp[i][w] = max(v1, v2);

	return dp[i][w];
}

int main() {

	cin >> n >> maxW; //number of items, max weight

	for (int i = 0; i < n; i++) { //get input
		int w, v;
		cin >> w >> v;
		item.push_back(make_pair(w, v));
	}

	cout << ks(0, 0) <<endl;

	return 0;
}
*/



//--by nested loops

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
