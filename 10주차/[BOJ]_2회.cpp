// https://www.acmicpc.net/problem/17298
// 17298번
// 오큰수

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int N;
    cin >> N;
    
    vector<int> arr;
    stack<int> s;
    for (int i{ 0 }; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        while (true) {
            if (s.empty()) {
                s.push(i);
                break;
            }
            int idx = s.top();
            if (arr[i] > arr[idx]) {
                arr[idx] = arr[i];
                s.pop();
            }
            else {
                s.push(i);
                break;
            }
        }
    }

    while (!s.empty()) {
        int idx = s.top();
        arr[idx] = -1;
        s.pop();
    }

    for (int i{ 0 }; i < N; i++) {
        cout << arr[i] << ' ';
    }
}