// https://www.acmicpc.net/problem/25501
// 25501¹ø
// Àç±ÍÀÇ ±ÍÀç

#include<iostream>
#include<cstring>
using namespace std;

int cnt{ 0 };

int recursion(const char* s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main() {
	int t;
	cin >> t;

	string s;
	for (int i{ 0 }; i < t; i++) {
		cin >> s;

		cnt = 0;
		cout << isPalindrome(s.c_str()) << " " << cnt << '\n';
	}
}