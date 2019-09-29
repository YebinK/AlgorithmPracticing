#include <iostream>
#include <stdio.h>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX_SIZE 25

int n;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int group[MAX_SIZE* MAX_SIZE] = { 0, }; //25*25
int groupId = 0;

void DFS(int x, int y) {

	stack<pair<int, int>> s;
	s.push(make_pair(x, y));

	visited[x][y] = true;
	group[groupId]++;

	int xySet[] = { -1, 0, 1, 0, 0, -1, 0, 1 }; //even index : X,  odd index : Y

	while (!s.empty()) {

		x = s.top().first;
		y = s.top().second;

		s.pop();

		for (int i = 0 ; i < 4 ; i++) { //search top, bottom, left, right

			int newX = x + xySet[2 * i];
			int newY = y + xySet[2 * i + 1];

			if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue; //out of range(map)

			if (map[newX][newY] == 1 && !visited[newX][newY]) {
				s.push(make_pair(newX, newY));
				visited[newX][newY] = true;
				group[groupId]++;
			}
		}


	}

}


int main() {
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) { //create new group and call DFS()
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				groupId++;
				DFS(i, j);
			}
		}
	}

	sort(group + 1, group + 1 + groupId);


	cout << groupId << '\n';

	for (int i = 1; i <= groupId; i++) {
		cout << group[i] << '\n';
	}
	return 0;
}