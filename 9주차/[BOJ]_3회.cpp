// https://www.acmicpc.net/problem/1100
// 1100╧Ь
// го╬А д╜

#include<iostream>
#include<vector>
using namespace std;

char paint[8][8] = { 0 };
char a[8] = { 'F', '.', 'F', '.', 'F', '.', 'F', '.' };
char b[8] = { '.', 'F', '.', 'F', '.', 'F', '.', 'F' };

int set1() {
	int result{ 0 };
	for (int j{ 0 }; j < 8; j++) {
		for (int i{ 0 }; i < 8; i++) {  // b, a, b, a...
			if (j % 2 == 0) {  // i == 0, 2, 4...
				if (b[i] == '.' && paint[j][i] == 'F') {
					result++;
				}
			}
			else {  // i == 1, 3, 5...
				if (a[i] == '.' && paint[j][i] == 'F') {
					result++;
				}
			}
		}
	}

	return result;
}

int main() {
	for (int i{ 0 }; i < 8; i++) {
		for (int j{ 0 }; j < 8; j++) {
			cin >> paint[i][j];
		}
	}

	cout << set1();
}