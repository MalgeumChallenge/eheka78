// https://www.codetree.ai/missions/2/problems/longest-decreasing-subsequence/description
// 최대 감소 부분 수열

/*dp*/

#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[1000] = { 0 };
    for (int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }

    int dp[1001] = { 0 };
    for (int i{ 0 }; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result{ 0 };
    for (int i{ 0 }; i < n; i++) {
        result = max(result, dp[i]);
    }
    cout << result << '\n';
}