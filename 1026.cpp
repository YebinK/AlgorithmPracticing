#include <iostream>
using namespace std;

#define max_size 50

void swap(int &p, int &q) {
	int tmp = p;
	p = q;
	q = tmp;
}

int main() {

	int n, A[max_size], B[max_size];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < n - 1; i++) { //sort A
		for (int j = i + 1; j < n; j++) {
			if (A[i] > A[j]) swap(A[i], A[j]);
		}
	}

	for (int i = 0; i < n - 1; i++) { //sort B
		for (int j = i + 1; j < n; j++) {
			if (B[i] < B[j]) swap(B[i], B[j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += A[i] * B[i];
	}

	cout << answer;
}