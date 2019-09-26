#include <iostream>
#include <queue>
using namespace std;

int main() {
	
	int testcase; //number of testcase
	cin >> testcase;

	int *answer = new int[testcase];

	for (int i = 0; i < testcase; i++) {
		int n, index; //number of documents, result index

		cin >> n >> index;

		queue<pair<int, int>> q;
		priority_queue<int> pq; //sorting documents with priority

		for (int j = 0; j < n; j++) {
			int input; //priority of document
			cin >> input;
			q.push(pair<int, int>(input, j)); //push the priority and doc index into the queue
			pq.push(q.back().first);
		}

		int result = 1;

		while (!q.empty()) {
			if (q.front().first == pq.top()) { //top priority. printed

				if (q.front().second == index) {
					answer[i] = result;
					break;
				}
				pq.pop();
				q.pop();
				result++;

			} else { //not printed
				int tmpDoc = q.front().first;
				int tmpIndex = q.front().second;
				q.pop();
				q.push(pair<int, int>(tmpDoc, tmpIndex));
			}
		}

	}

	for (int i = 0; i < testcase; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}