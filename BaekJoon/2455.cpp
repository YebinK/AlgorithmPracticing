#include <iostream>
using namespace std;

const int station = 4; //number of stations

int main() {

	int in[station], out[station];
	int now = 0, max = 0;

	for (int i = 0; i < station; i++) {
		cin >> out[i] >> in[i];
	}

	for (int i = 0; i < station; i++) {
		now -= out[i]; //get out first
		now += in[i]; //then get in

		if (now > max) max = now;
	}

	cout << max;

	return 0;
}