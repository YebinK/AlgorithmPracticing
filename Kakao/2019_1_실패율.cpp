#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool desc(pair<double, int> a, pair<double, int> b) { //sort descending order
	if (a.first != b.first)	return a.first > b.first;
	else return a.second < b.second;
}

int main() {

	int N;
	vector<int> stages;
	vector<int> answer;
	vector<pair<double, int>> record;

	for (int i = 1; i <= N; i++) {
		double top = 0;
		double bottom = 0;

		for (int j = 0; j < stages.size(); j++) { //get failure rate
			if (stages[j] >= i) bottom++;
			if (stages[j] == i) top++;
		}
		if (bottom == 0) record.push_back(make_pair(0, i)); //push results
		else record.push_back(make_pair(top / bottom, i));
	}

	sort(record.begin(), record.end(), desc);

	for (int i = 0; i < record.size(); i++) {
		answer.push_back(record[i].second);
	}

	return 0;
}