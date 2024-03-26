// https://www.acmicpc.net/problem/1987
// 1987��
// ���ĺ�

/*
�Ƹ� dfs����
*/

#include<iostream>
using namespace std;

char arr[21][21] = {};
int r, c;  // 1 <= r, c <= 20
bool english[26] = { false };  // ���ĺ� 26��
int result{ 0 };

bool isInside(int y, int x) {
	return y >= 0 && x >= 0 && y < r&& x < c;
}

void dfs(int y, int x, int count) {
	int XX[4] = { 1, -1, 0, 0 };
	int YY[4] = { 0, 0, 1, -1 };

	result = { result < count ? count : result };  // ���� ū �� ���� ����

	int temp{ count };
	for (int i{ 0 }; i < 4; i++) {  // ������� �˻�
		int ny = y + YY[i];
		int nx = x + XX[i];

		if (isInside(ny, nx) && english[arr[ny][nx] - 'A'] == false) {
			english[arr[ny][nx] - 'A'] = true;
			dfs(ny, nx, temp += 1);
			temp = count;  // �̰� �򰥷���.....****************
			english[arr[ny][nx] - 'A'] = false;  // �̰͵� ���� �� ��...
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	for (int i{ 0 }; i < r; i++) {
		for (int j{ 0 }; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	english[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << result << '\n';
}