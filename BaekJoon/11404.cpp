#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_COST 999999
#define MAX_CITY 101

int main() {

	int n, m; //number of cities, buses
	int cost[MAX_CITY][MAX_CITY];

	cin >> n >> m;

	int start, end, value;

	for (int i = 1; i <= n; i++) { //initialization
		for (int j = 1; j <= n; j++) {
			if (i == j) cost[i][j] = 0;
			else cost[i][j] = MAX_COST;
		}
	}

	for (int i = 0; i < m; i++) { //get input
		cin >> start >> end >> value;

		if (cost[start][end] > value)
			cost[start][end] = value;
	}

	for (int via = 1; via <= n; via++) {
		for (int i = 1; i <= n; i++) { //i is start node
			for (int j = 1; j <= n; j++) { //j is end node
				cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) { //print result
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == MAX_COST) { //exception handling
				cout << 0 << ' ';
				continue;
			}
			cout << cost[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}