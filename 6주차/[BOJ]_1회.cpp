// 1931��
// ȸ�ǽ� ����

/*
1. ������ �ð����� ���� = t
2. ���� ���� �����°� ��������
3. t ������� �����ϴ� �ð��� ù ��° ������ �ð����� ������ �� �ð� ������ �ð��� ������ �ð����� �����ϱ�. count++
4. count ���
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, s, e, count{ 1 };  // ȸ�Ǽ�: 1 �� N �� 100,000
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