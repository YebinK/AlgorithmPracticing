#include <iostream>
using namespace std;

int n;
int lotto[50];
int selected[6];

void DFS(int start, int depth) {

	if (depth == 6) { //flush
		for (int i = 0; i < 6; i++) {
			cout << selected[i] << " ";
		} cout << "\n";
		return;
	}

	for (int i = start; i < n; i++) { //brute force with DFS
		selected[depth] = lotto[i];
		DFS(i + 1, depth + 1);
	}
}

int main() {

	while (cin >> n && n) { //get input
		for (int i = 0; i < n; i++) {
			cin >> lotto[i];
		}

		DFS(0, 0);
		cout << "\n";
	}

	return 0;
}