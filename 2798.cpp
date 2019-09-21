#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, m, result = 0;
	cin >> n >> m;

	int card[101];

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n-2 ; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = card[i] + card[j] + card[k];

				if (temp <= m && temp > result)
					result = temp;
			}
		}
	}

	cout << result;

	return 0;
}