#include <iostream>
using namespace std;

int main() {
	int num, result = 0;

	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0, j = 0; j < num; j++) {
		for (i = 0; i <= j; i++) {
			result += arr[i];
		}
	}

	cout << result;

	return 0;

}