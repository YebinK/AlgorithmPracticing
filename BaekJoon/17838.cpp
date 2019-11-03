#include <stdio.h>
using namespace std;

#define max_length 10001

int main() {

	int testcase, result;
	int answer[101];
	char cmd[max_length];

	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++) {
		result = 0;
		scanf("%s", &cmd);

		if (cmd[7] == '\0') {
			if (cmd[1] != cmd[2]) {
				if (cmd[0] == cmd[1] && cmd[1] == cmd[4] && cmd[2] == cmd[3] && cmd[3] == cmd[5] && cmd[5] == cmd[6]) {
					result = 1;
				}
			}
		}
		answer[i] = result;
	}

	for (int i = 0; i < testcase; i++) {
		printf("%d\n", answer[i]);
	}

}