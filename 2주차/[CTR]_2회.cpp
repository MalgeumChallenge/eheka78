// https://www.codetree.ai/missions/2/problems/minimum-sum-path-in-square/description
// 격자 안에서 한 칸씩 전진하는 DP / 정수 사각형 최소 합

/* DP */

#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int arr[101][101] = { 0 };
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i{ n - 1 }; i >= 0; i--) {
        arr[0][i - 1] += arr[0][i];
    }

    for (int i{ 1 }; i < n; i++) {
        arr[i][n - 1] = arr[i - 1][n - 1] + arr[i][n - 1];
    }

    for (int i = 1; i < n; i++)
        for (int j = n - 2; j >= 0; j--)
            arr[i][j] = min(arr[i - 1][j], arr[i][j + 1]) + arr[i][j];

    cout << arr[n - 1][0];
}