#include <iostream>
#include <algorithm>
using namespace std;

const int userMax = 100;
const int INF = 99999;

int main() {
	
	int linked[userMax][userMax];
	int user, link, winner = INF, winnerIndex = 0;

	cin >> user >> link; //number of users and links

	for (int i = 1; i <= user; i++) {
		for (int j = 1; j <= user; j++) {
			if (i == j) linked[i][i] = 0;
			else linked[i][j] = INF;
		}
	}

	for (int i = 0; i < link; i++) { //add links
		int a, b;
		cin >> a >> b;
		linked[a][b] = 1;
		linked[b][a] = 1;
	}

	for (int k = 1; k <= user; k++) { //Floyd-Warshall Algorithm
		for (int i = 1; i <= user; i++) {
			for (int j = 1; j <= user; j++) {
				if (i == j) continue;
				
				linked[i][j] = min(linked[i][j], linked[i][k] + linked[k][j]);
			}
		}
	}

	for (int i = 1; i <= user; i++) {
		for (int j = 1; j <= user; j++) {
			linked[i][0] += linked[i][j];
		}
		if (winner > linked[i][0]) {
			winner = linked[i][0];
			winnerIndex = i;
		}
	}

	cout << winnerIndex;

	return 0;
}