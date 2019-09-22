#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase, student;
	double avg, avgHigh, result;
	vector<double> resultSet;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> student;

		vector<int> scoreSet;
		avg = 0;

		for (int i = 0; i < student; i++) {
			int score;
			cin >> score;

			scoreSet.push_back(score);
			avg += score;
		}

		avg /= student;
		avgHigh = 0; //Students counts who has higher score than avg

		for (int i = 0; i < student; i++) {
			if (scoreSet[i] > avg) {
				avgHigh++;
			}
		}

		result = avgHigh / student;
		result *= 100; //percent
		resultSet.push_back(result);

	}

	for (int i = 0; i < testcase; i++) {
		cout << fixed;
		cout.precision(3);
		cout << resultSet[i] << "%" << "\n";
	}
}