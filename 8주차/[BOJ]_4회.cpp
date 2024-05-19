// https://www.acmicpc.net/problem/4779
// 4779번
// 칸토어 집합

#include<iostream>
#include<math.h>
using namespace std;

int n, LineLen;
string str{ "" };

void aa(int s, int sz) {
	if (sz == 1) {
		return;
	}

	aa(s, sz / 3);
	for (int i{ s + sz / 3 }; i < s + (sz / 3) * 2; i++) {
		str[i] = ' ';
	}
	aa(s + sz / 3, sz / 3);
	aa(s + (sz / 3) * 2, sz / 3);
}

int main() {
	while (cin >> n) {
		LineLen = pow(3, n);
		str = "";
		for (int i{ 0 }; i <= LineLen; i++) {
			str += '-';
		}

		aa(1, LineLen);

		// output: idx 1부터 LineLen까지
		for (int i{ 1 }; i <= LineLen; i++) {
			cout << str[i];
		}
		cout << '\n';
	}
}