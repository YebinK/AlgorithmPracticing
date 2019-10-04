#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 11
int main() {

	int testcase;
	int result[MAX_SIZE] = { 0, 1, 2, 4, 0, };
	vector<int> v;

	cin >> testcase;

	for (int i = 4; i < MAX_SIZE; i++) {
		result[i] = result[i - 1] + result[i - 2] + result[i - 3];
	}

	for (int i = 0; i < testcase; i++) {
		int n;
		cin >> n;

		v.push_back(result[n]);
	}

	for (int i = 0; i < testcase; i++) {
		cout << v[i] <<endl;
	}

	return 0;
}