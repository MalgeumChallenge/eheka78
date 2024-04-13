// https://www.acmicpc.net/problem/11279

// 11729번
// 최대 힙

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<int> result = {};
    int n;
    cin >> n;

    priority_queue<int> q = {};  // 우선순위 큐
    for (int i = {0}; i < n; i++) {
        int x;
        cin >> x;

        if (x != 0) {
            q.push(x);
        }
        else {
            if (q.empty()) {
                result.push_back(0);
            }
            else {
                result.push_back(q.top());
                q.pop();
            }
        }
    }

    // output
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
}