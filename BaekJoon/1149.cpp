#include <iostream>
#include <algorithm>
using namespace std;

#define max_size 1001

int n; //number of houses
int cost[max_size][3];

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) { //get input
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; //r, g, b
	}

	for (int i = 0; i < n; i++) {

		if (i == 0) continue;
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + cost[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + cost[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + cost[i][2];

	}

	int tmp = min(cost[n - 1][0], cost[n - 1][1]); //do min() two times
	cout << min(tmp, cost[n - 1][2]);

	return 0;
}