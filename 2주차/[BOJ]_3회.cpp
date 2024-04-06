// https://www.acmicpc.net/problem/2447
// 2447¹ø
// º° Âï±â - 10

#include <iostream>
using namespace std;

void star(int N, int i, int j) {
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1) {
		cout << " ";
	}
	else {
		if (N / 3 == 0) {
			cout << '*';
		}
		else {
			star(N / 3, i, j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N{ 0 };  // NÀº 3ÀÇ °ÅµìÁ¦°ö  // 1 ¡Â k < 8
	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			star(N, i, j);
		}
		cout << "\n";
	}
}