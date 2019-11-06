#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {

	int n;
	vector<pair<int, int>> vp;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vp.push_back(make_pair(y, x));
	}

	sort(vp.begin(), vp.end());

	for (int i = 0; i < n; i++) {
		cout << vp[i].second << ' ' << vp[i].first <<'\n';
	}
	return 0;
}