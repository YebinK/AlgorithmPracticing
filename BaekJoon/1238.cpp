#include <stdio.h>
using namespace std;

#define max_size 1001
#define max_weight 999999

int village[max_size][max_size];

int main() {

	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	for (int i = 1; i <= n; i++) { //initialization
		for (int j = 1; j <= n; j++) {
			if (i == j) village[i][j] = 0;
			else village[i][j] = max_weight;
		}
	}

	for (int i = 0; i < m; i++) { //get links
		int start, end, weight;
		scanf("%d %d %d", &start, &end, &weight);

		village[start][end] = weight;
	}

	for (int k = 1; k <= n; k++) { //floyd algorithm
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (village[i][j] > village[i][k] + village[k][j]) village[i][j] = village[i][k] + village[k][j];
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = result > village[i][x] + village[x][i] ? result : village[i][x] + village[x][i];
	}
	printf("%d", result);

	return 0;

}