#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define MAX_SIZE 101

int n, m; //n * m maze

int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> q;

int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { -1, 0, 1, 0 };


void BFS(int x, int y) {

	if (x == n && y == m) {
		return;
	}

	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;

		for (int i = 0; i < 4; i++) {
			int newX = x + x_move[i];
			int newY = y + y_move[i];

			if (0 < newX && newX <= n && 0 < newY && newY <= m) { //if maze[newX][newY] exists in the maze
				if (maze[newX][newY] > 0 && !visited[newX][newY]) { //BFS
					maze[newX][newY] = maze[x][y] + 1;
					visited[newX][newY] = true;
					q.push(make_pair(newX, newY));
				}
			}
		}
		q.pop();
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	BFS(1, 1);

	printf("%d", maze[n][m]);
	return 0;
}