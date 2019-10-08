#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define MAX_SIZE 501

int main() {

	int n;
	int tri[MAX_SIZE][MAX_SIZE];

	cin >> n;

	for (int i = 0; i < n; i++) { //get triangle
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	int max = 0;

	for (int i = 1, k = 0; i < n; i++) { //add max value to next(tri[i]) layer
		k = 0;
		while (k <= i) {
			if (k == 0) { //if tri[i][0], cannot choose value
				tri[i][k] += tri[i - 1][k];
				k++;
				continue;
			}
			else if (k == i) { //if tri[i][i], also cannot choose value
				tri[i][k] += tri[i - 1][k - 1];
				break;
			}
			max = (tri[i - 1][k - 1] > tri[i - 1][k] ? tri[i - 1][k - 1] : tri[i - 1][k]); //get max value
			tri[i][k] += max;	//put into next layer
			k++;
		}
	}

	sort(tri[n - 1], tri[n - 1] + n);

	
	cout << tri[n - 1][n - 1];

	return 0;
}