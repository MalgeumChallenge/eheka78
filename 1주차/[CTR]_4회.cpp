// https://www.codetree.ai/missions/2/problems/seperate-village/description
// 마을 구분하기

/*DFS문제*/

#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct bin {
    int y, x;
};

int n;
int arr[25][25] = { 0 };
bool visited[25][25] = { false };
int vcnt{ 0 };
vector<int> pcnt = {};

bool isInside(int y, int x) {
    return y >= 0 && x >= 0 && y < n&& x < n;
}

void dfs(int nny, int nnx) {
    int Y[4] = { 0,0,1,-1 };
    int X[4] = { 1,-1,0,0 };
    int cnt{ 1 };

    queue<bin> q{};
    q.push({ nny, nnx });
    while (!q.empty()) {
        int yy{ q.front().y };
        int xx{ q.front().x };
        q.pop();

        for (int i{ 0 }; i < 4; i++) {
            int ny{ yy + Y[i] };
            int nx{ xx + X[i] };

            if (isInside(ny, nx) && arr[ny][nx] == 1 && visited[ny][nx] == false) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
                cnt++;
            }
        }
    }

    pcnt.push_back(cnt);
    vcnt++;
}


int main() {
    cin >> n;
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            if (arr[i][j] == 1 && visited[i][j] == false) {
                visited[i][j] = true;
                dfs(i, j);
            }
        }
    }

    cout << vcnt << '\n';
    sort(pcnt.begin(), pcnt.end());
    for (int i : pcnt) {
        cout << i << '\n';
    }
}