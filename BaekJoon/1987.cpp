#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define max_size 21

char board[max_size][max_size];
vector<char> v; //visited node

int r, c;
int move_r[4] = { -1, 0, 1, 0 };
int move_c[4] = { 0, -1, 0, 1 };
int maxCount = 0;

int visited(char ch) {

	if (find(v.begin(), v.end(), ch) != v.end()) return 1;
	else return 0;
}

void DFS(int x, int y) {
	
	if (visited(board[x][y])) return;

	v.push_back(board[x][y]);

	for (int i = 0; i < 4; i++) { //left, right, up, down
		int nextX = x + move_r[i];
		int nextY = y + move_c[i];
		if (nextX < 0 || nextX >= r || nextY < 0 || nextY >= c) continue; //index out of the board
		DFS(nextX, nextY);
	}

	if (v.size() > maxCount) maxCount = v.size();
	v.pop_back();

}

int main() {
	
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	DFS(0, 0);

	cout << maxCount;

	return 0;
}