// https://www.codetree.ai/missions/2/problems/graph-traversal/description
// 그래프 탐색

#include <iostream>
using namespace std;

int n, m;
bool arr[1001][1001] = { false };
bool visit[1001] = { false };
int cnt;

void dfs(int start) {
    for (int i{ 1 }; i <= n; i++) {
        if (arr[start][i] == true && !visit[i]) {
            visit[i] = true;
            cnt++;
            dfs(i);
        }
    }
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    int y, x;
    for (int i{ 0 }; i < m; i++) {
        cin >> y >> x;
        arr[y][x] = true;
        arr[x][y] = true;
    }
    visit[1] = true;
    dfs(1);
    cout << cnt;
    return 0;
}