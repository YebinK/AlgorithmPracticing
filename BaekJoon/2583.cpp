#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int area[100][100] = { 0, };		//graph paper
int visited[100][100] = { 0, };		//DFS visited check
vector<int> result;

int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, -1, 0, 1 };

int DFS(int x, int y) {
	int count = 1;

	if (visited[x][y] || area[x][y]) return 0;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
			count += DFS(nextX, nextY);
		}
	}

	return count;
}

void fillArea(int LX, int LY, int RX, int RY) { //fill graph paper with 1
	for (int i = LX; i < RX; i++) {
		for (int j = LY; j < RY; j++) {
			area[i][j] = 1;
		}
	}
}

int main() {

	int k;

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int leftX, leftY, rightX, rightY;
		cin >> leftX >> leftY >> rightX >> rightY;

		fillArea(leftX, leftY, rightX, rightY);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!area[i][j] && !visited[i][j])
				result.push_back(DFS(i, j));
		}
	}
		
	sort(result.begin(), result.end());

	cout << result.size() <<'\n';
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	return 0;
}