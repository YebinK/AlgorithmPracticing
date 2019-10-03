#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 1000

int m, n, day = 0;
int box[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> q;
int x_adj[4] = { -1, 0, 1, 0 };
int y_adj[4] = { 0, -1, 0, 1 };

void BFS(int y, int x) {

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) { //search for top, bottom, left, right area
		int newY = y + y_adj[i];
		int newX = x + x_adj[i];

		if (newY < 0 || newY >= n) continue; //out of the map
		if (newX < 0 || newX >= m) continue;

		if (box[newY][newX] == 0 && !visited[newY][newX]) {
			box[newY][newX] = box[y][x] + 1;
			q.push(make_pair(newY, newX));

			day = box[y][x];
		}
	}
}

int main() {
	cin >> m >> n; //n * m map

	for (int i = 0; i < n; i++) { //input
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		BFS(q.front().first, q.front().second);
		q.pop();
	}

	for (int i = 0; i < n; i++) { //check if non-visited area exists
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day;

	return 0;
}
