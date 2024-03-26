// https://www.acmicpc.net/problem/1987
// 1987번
// 알파벳

/*
아마 dfs문제
*/

#include<iostream>
using namespace std;

char arr[21][21] = {};
int r, c;  // 1 <= r, c <= 20
bool english[26] = { false };  // 알파벳 26개
int result{ 0 };

bool isInside(int y, int x) {
	return y >= 0 && x >= 0 && y < r&& x < c;
}

void dfs(int y, int x, int count) {
	int XX[4] = { 1, -1, 0, 0 };
	int YY[4] = { 0, 0, 1, -1 };

	result = { result < count ? count : result };  // 가장 큰 수 고르기 위한

	int temp{ count };
	for (int i{ 0 }; i < 4; i++) {  // 사방으로 검사
		int ny = y + YY[i];
		int nx = x + XX[i];

		if (isInside(ny, nx) && english[arr[ny][nx] - 'A'] == false) {
			english[arr[ny][nx] - 'A'] = true;
			dfs(ny, nx, temp += 1);
			temp = count;  // 이걸 헷갈렸음.....****************
			english[arr[ny][nx] - 'A'] = false;  // 이것도 생각 좀 함...
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