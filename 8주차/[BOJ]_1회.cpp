// https://www.acmicpc.net/problem/15650
// 15650¹ø
// N°ú M(2)

#include <iostream>
using namespace std;

int n, m;
int arr[9] = {};
bool visited[9] = {};

void dfs(int a, int cnt){
    if (cnt == m) {
        for (int i{ 0 }; i < m; i++) {
            cout << arr[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i{ a }; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    arr[0] = 0;
    visited[0] = 0;

    dfs(1, 0);
    return 0;
}