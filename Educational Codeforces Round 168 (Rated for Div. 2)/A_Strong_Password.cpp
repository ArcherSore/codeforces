// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    if (n == 1) {
        cout << s;
        if (s[n - 1] != 'a') {
            cout << char(s[n - 1] - 1);
        } else {
            cout << char(s[n - 1] + 1);
        }
        cout << '\n';
        return;
    }

    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        cout << s[i];
        if (!flag && s[i] == s[i + 1]) {
            if (s[i] != 'a') {
                cout << char(s[i] - 1);
            } else {
                cout << char(s[i] + 1);
            }
            flag = 1;
        }
    }
    cout << s[n - 1];
    if (!flag) {
        if (s[n - 1] != 'a') {
            cout << char(s[n - 1] - 1);
        } else {
            cout << char(s[n - 1] + 1);
        }
        flag = 1;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}