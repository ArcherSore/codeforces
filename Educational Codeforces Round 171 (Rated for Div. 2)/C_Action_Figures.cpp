#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pos.push(i);
        }
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = i + 1;
    }

    int st = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            continue;
        }
        while (!pos.empty() && pos.top() > i) {
            pos.pop();
        }
        if (!pos.empty()) {
            res[i] = 0;
            pos.pop();
        } else {
            st = i;
            break;
        }
    }
    vector<int> ones;
    for (int i = 0; i <= st; i++) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }
    if (ones.size() % 2) {
        for (int i = ones.size() / 2 + 1; i < ones.size(); i++) {
            res[ones[i]] = 0;
        }
    } else {
        for (int i = ones.size() / 2; i < ones.size(); i++) {
            res[ones[i]] = 0;
        }
    }

    LL ans = 0;
    for (LL x : res) {
        ans += x;
    }
    cout << ans << '\n';
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