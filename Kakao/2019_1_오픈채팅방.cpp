// https://www.welcomekakao.com/learn/courses/30/lessons/42888?language=cpp

#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {

	vector<string> record;
	vector<string> answer;
	map<string, string> m;

	for (int i = 0; i < record.size(); i++) {
		int cmdIndex = record[i].find(' ');
		string cmd = record[i].substr(0, cmdIndex); //get cmd

		record[i] = record[i].substr(cmdIndex + 1);
		int uidIndex = record[i].find(' ');

		string uid, name;
		if (uidIndex < 0) uid = record[i]; //separate uid and name
		else {
			uid = record[i].substr(0, uidIndex);
			name = record[i].substr(uidIndex + 1);

			m[uid] = name;
		}

		if (cmd == "Enter") {
			answer.push_back(uid + " 님이 들어왔습니다.");
		}
		else if (cmd == "Leave") {
			answer.push_back(uid + " 님이 나갔습니다.");
		}
	}

	for (int i = 0; i < answer.size(); i++) { //change to matched name
		int nameIndex = answer[i].find(' ');
		string id = answer[i].substr(0, nameIndex);
		answer[i] = answer[i].substr(nameIndex + 1);
		answer[i] = m[id] + answer[i];
	}

	return 0;
}
