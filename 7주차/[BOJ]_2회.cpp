// https://www.acmicpc.net/problem/1715
// 1715변
// 카드 정렬하기

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i{ 0 }; i < n; i++) {
		cin >> a;
		q.push(a);
	}

	int sum = 0;
	int result = 0;
	int  b;
	while (q.size() != 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a + b);
		result += a + b;
	}
	

	cout << result;
	return 0;
}