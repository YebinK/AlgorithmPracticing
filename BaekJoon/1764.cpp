#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define max_size 500001

int n, m;
string heard[max_size];
string seen[max_size];
vector<string> common;

void binarySearch(string str) { //Binary Search
	int low = 0;
	int high = m - 1;

	while (low <= high) {
		int middle = (low + high) / 2;

		if (str < seen[middle]) {
			high = middle - 1;
		}
		else if (str > seen[middle]) {
			low = middle + 1;
		}
		else {
			common.push_back(str);
			return;
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> heard[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> seen[i];
	}

	sort(heard, heard + n);
	sort(seen, seen + n);

	for (int i = 0; i < n; i++) {
		binarySearch(heard[i]);
	}
	
	sort(common.begin(), common.end());

	cout << common.size() << '\n';

	for (int i = 0; i < common.size(); i++) {
		cout << common[i] << '\n';
	}

	return 0;
}