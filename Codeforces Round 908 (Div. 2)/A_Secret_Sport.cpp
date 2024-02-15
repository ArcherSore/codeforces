#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void cal(string &s, int len, int &a, int &b) {
    int n = s.size();
    int num_a = 0, num_b = 0, cnt = 0;
    for (int i = 0; i < n; i++, cnt++) {
        if (s[i] == 'A') num_a += 1;
        else num_b += 1;
        if (num_a == len || num_b == len || i == n - 1) {
            cnt = 0;
            if (num_a > num_b) a += 1;
            if (num_b > num_a) b += 1;
            num_a = 0, num_b = 0;
        }
    }
    return;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a_win = 0, b_win = 0;
    for (int i = 1; i <= n; i++) { // 枚举长度
        int a = 0, b = 0;
        cal(s, i, a, b);
        if ((a > b && s.back() == 'B') || a < b && s.back() == 'A') continue;
        if (a > b) {
            a_win += 1;
        } else if (a < b) {
            b_win += 1;
        }
    }

    if (a_win && !b_win) {
        cout << "A\n";
    } else if (!a_win && b_win) {
        cout << "B\n";
    } else {
        cout << "?\n";
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}