//11650. ��ǥ �����ϱ�


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {

	int n, x, y;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pair<int, int>(x, y));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}