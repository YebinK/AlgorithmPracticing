#include <stdio.h>
#include <algorithm>
using namespace std;

#define max_size 100001

int main() {

	int n, data[max_size], sum[max_size];
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) { //get input
		scanf("%d", &data[i]);
	}

	for (int i = 1; i <= n; i++) { //add data[i] or renew the sum
		if (data[i] < sum[i - 1] + data[i]) {
			sum[i] = sum[i - 1] + data[i];
		}
		else sum[i] = data[i];
	}

	sort(sum + 1, sum + n + 1);
	
	printf("%d", sum[n]);
	return 0;
}