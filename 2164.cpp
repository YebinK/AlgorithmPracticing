#include <iostream>
#include <queue>
using namespace std;

int main() {

	int n;

	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n ; i++) {
		q.push(i);
	}

	while (!q.empty()) {

		if (q.size() == 1) break;

		q.pop(); //버리기
		
		int num = q.front(); //뒤로 보내기
		q.push(num);
		q.pop();
	}

	cout << q.front();

	return 0;
}