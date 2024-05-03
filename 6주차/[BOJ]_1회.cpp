// 1931번
// 회의실 배정

/*
1. 끝나는 시간으로 정렬 = t
2. 재일 빨리 끝나는걸 시작으로
3. t 순서대로 시작하는 시간이 첫 번째 끝나는 시간보다 늦으면 그 시간 끝나는 시간을 끝나는 시간으로 설정하기. count++
4. count 출력
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, s, e, count{ 1 };  // 회의수: 1 ≤ N ≤ 100,000
vector<pair<int, int>> t = {};  // end, start

int main() {
	cin >> n;

	for (int i{ 0 }; i < n; i++) {
		cin >> s >> e;
		t.push_back(pair<int, int>(e, s));
	}

	sort(t.begin(), t.end());

	e = t[0].first;
	::count = 1;
	for (int i{ 1 }; i < n; i++) {
		if (e <= t[i].second) {
			::count++;
			e = t[i].first;
		}
	}
	cout << ::count << '\n';
}