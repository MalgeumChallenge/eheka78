// https://www.acmicpc.net/problem/11286
// 11286번
// 절댓값 힙

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a;
	priority_queue<int, vector<int>, less<int>> less; // 음수  // 내림차순
	priority_queue<int, vector<int>, greater<int>> greater;  // 양수  // 오름차순
	for (int i{ 0 }; i < n; i++) {
		cin >> a;
		if (a < 0) {
			less.push(a);
		}
		else if (a > 0) {
			greater.push(a);
		}
		else if (a == 0) {
			if (less.empty() && greater.empty()) {
				cout << 0 << "\n";
			}
			else if (less.empty()) {
				cout << greater.top() << "\n";
				greater.pop();
			}
			else if (greater.empty()) {
				cout << less.top() << "\n";
				less.pop();
			}
			else {
				if (-less.top() > greater.top()) {
					cout << greater.top() << "\n";
					greater.pop();
				}
				else {
					cout << less.top() << "\n";
					less.pop();
				}
			}
		}
	}
}