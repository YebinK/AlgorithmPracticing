#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, kim, lim, minIndex, maxIndex, round = 0;

	cin >> n >>kim >>lim; //#participants, Kim Index, Lim Index

	while (n > 0) {

		round++;
		
		minIndex = min(kim, lim);
		maxIndex = max(kim, lim);

		if (minIndex + 1 == maxIndex && minIndex % 2 == 1)
			break;

		if (n % 2 == 0)
			n /= 2;
		else
			n = (n + 1) / 2;

		if (kim % 2 == 0)
			kim /= 2;
		else
			kim = (kim + 1) / 2;

		if (lim % 2 == 0)
			lim /= 2;
		else
			lim = (lim + 1) / 2;

	}

	cout << round;

	return 0;
}