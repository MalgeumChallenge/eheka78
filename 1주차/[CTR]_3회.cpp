// https://www.codetree.ai/missions/2/problems/determine-escapableness-with-2-ways/description
// 두 방향 탈출 가능 여부 판단하기

#include <iostream>
#include<queue>
using namespace std;

struct bin {
    int y, x;
};

int n, m, result{ 0 };
bool visited[101][101] = { false };
int arr[101][101] = { 0 };  // 0~ n-1까지임

bool isInside(int y, int x) {
    return y >= 0 && x >= 0 && y < n&& x < m;
}

void dfs() {
    int Y[2] = { 0,1 };
    int X[2] = { 1,0 };

    queue<bin> q = {};
    q.push({ 0,0 });
    while (!q.empty()) {
        int yy{ q.front().y };
        int xx{ q.front().x };
        q.pop();

        for (int i{ 0 }; i < 2; i++) {
            int ny{ yy + Y[i] };
            int nx{ xx + X[i] };

            if (!visited[ny][nx] && arr[ny][nx] == 1) {
                if (isInside(ny, nx)) {
                    visited[ny][nx] = true;
                    q.push({ ny,nx });
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dfs();

    if (visited[n - 1][m - 1] == true) { cout << 1; }
    else { cout << 0; }
    return 0;
}