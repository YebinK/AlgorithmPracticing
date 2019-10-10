//Programmers 나머지 한 점 https://programmers.co.kr/learn/courses/18/lessons/1878

#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	ans.push_back(0); //initialization
	ans.push_back(0);

	ans[0] = v[0][0] ^ v[1][0] ^ v[2][0]; //XOR operation
	ans[1] = v[0][1] ^ v[1][1] ^ v[2][1];

	return ans;
}