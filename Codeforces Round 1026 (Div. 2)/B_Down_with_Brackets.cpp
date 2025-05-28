#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            v[i] = -1;
        } else {
            v[i] = 1;
        }
    }

    int sum = 0, flag = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum == 0 && i != n - 1) {
            flag = 1;
        }
    }

    if (!flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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