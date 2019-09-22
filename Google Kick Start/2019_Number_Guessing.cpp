//KickStart 2019
//Number Guessing using binary search

#include <iostream>
#include <string>
using namespace std;

int main() {

	int t, a, b, n, p, q;
	string word;
	cin >> t; //#testcase

	for (int i = 0; i < t; i++) {

		cin >> a >> b >> n; //exclusively lower bound, upper bound, and max number of guesses

		while (n >= 0) {

			q = (a + b) / 2;
			cout << q << '\n'; //my guess
			cin >> word;

			if (word == "CORRECT")
				break;
			else if (word == "TOO_SMALL") {
				a = q + 1;
				n--;
			}
			else { //TOO_BIG
				b = q - 1;
				n--;
			}
		}

	}

	return 0;
}
