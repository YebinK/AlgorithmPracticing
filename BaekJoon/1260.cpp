#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool visited[1001];
vector<int> linked[10000];
queue<int> q;

void DFS(int x) { //by recursion
	visited[x] = true;
	cout << x << " ";

	for (int i = 0; i < linked[x].size(); i++) {

		if (!visited[linked[x][i]]) {
			DFS(linked[x][i]);
		}
	}
}

void BFS(int x) { //by queue
	q.push(x);
	visited[x] = true;
	cout << x << " ";

	while (!q.empty()) {
		int k = q.front();

		for (int i = 0; i < linked[k].size(); i++) {
			if (!visited[linked[k][i]]) {
				q.push(linked[k][i]);
				visited[linked[k][i]] = true;
				cout << linked[k][i] << " ";
			}
		}
		q.pop();
	}

}

int main() {

	int m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		linked[a].push_back(b);
		linked[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) { //sort linked vector
		int k = linked[i].size();
		sort(linked[i].begin(), linked[i].end());
	}

	DFS(v);
	cout << '\n';

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}

	BFS(v);

	return 0;
}