#include <iostream>
#include <algorithm>
using namespace std;

#define max_size 1001

int main() {

	int n; //size of arr
	int arr[max_size], cost[max_size];

	cin >> n;

	for (int i = 0; i < n; i++) { //get input, initialize cost array
		cin >> arr[i];
		cost[i] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { //check smaller index than i
			if (arr[j] < arr[i]) {
				cost[i] = max(cost[i], cost[j] + 1);
			}
		}
	}

	sort(cost, cost + n); //in order to get max value, sort cost array with STL sort()
	cout << cost[n - 1];

	return 0;
}