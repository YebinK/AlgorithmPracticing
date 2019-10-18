#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {

	int n;
	vector<pair<int, int>> data; //weight, height
	int answer[50][2];

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int weight, height;
		cin >> weight >> height;
		data.push_back(make_pair(weight, height));
	}

	for (int i = 0; i < n; i++) { //initialization
		answer[i][1] = 1;
	}


	for (int i = 0; i < data.size(); i++) {
		for (int j = i + 1; j < data.size(); j++) {
			if (data[i].first > data[j].first && data[i].second > data[j].second) {
				answer[j][1]++; //degrade j
			} else if (data[i].first < data[j].first && data[i].second < data[j].second){
				answer[i][1]++; //degrade i
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i][1] << " ";
	}

	return 0;
}