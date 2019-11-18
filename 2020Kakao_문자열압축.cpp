#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++) {
		string pivot = s.substr(0, i);
		int sameCount = 1;
		int iCount = i;
		
		for (int j = i; j < s.length(); j += i) {

			if (i != s.substr(j, i).length()) {
				iCount += s.substr(j, i).length();
				break;
			}

			if (pivot == s.substr(j, i)) sameCount++;
			else {
				if (sameCount > 1) iCount += to_string(sameCount).length();
				iCount += pivot.length();

				pivot = s.substr(j, i);
				sameCount = 1;
			}
		}
		if (sameCount > 1) iCount += to_string(sameCount).length();
		
		if (iCount < answer) answer = iCount;
	}

	cout << answer;

	return 0;
}