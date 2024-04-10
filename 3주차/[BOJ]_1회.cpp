// https://www.acmicpc.net/problem/2156

// 2156번
// 포도주 시식

/*DP*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n + 1] = { 0, };
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long long dp[n + 1];

    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max({ dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i], dp[i - 1] });
    }

    cout << dp[n] << endl;
}