#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool same_cnt(vector<int> &a, vector<int> &b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int p = 0;
    while (p <= n - p - 1 && s[p] == s[n - p - 1]) {
        p++;
    }
    if (p > n - p - 1) {
        cout << 0 << '\n';
        return;
    }
    string t;
    for (int i = p; i < n - p; i++) {
        t.push_back(s[i]);
    }

    int m = t.size();
    vector<int> lcnt(26), rcnt(26);
    for (int i = 0; i < m / 2; i++) {
        lcnt[t[i] - 'a']++;
    }
    for (int i = (m + 1) / 2; i < m; i++) {
        rcnt[t[i] - 'a']++;
    }
    if (same_cnt(lcnt, rcnt)) {
        p = m / 2 - 1;
        while (t[p] == t[m - p - 1]) {
            p--;
        }
        cout << p + 1 << '\n';
        return;
    }

    // 对称轴左边不等于右边
    vector<int> cnt(26);
    for (int i = 0; i < m; i++) {
        cnt[t[i] - 'a']++;
    }
    int res = m;
    vector<int> tcnt(26);
    for (int i = 0; i < m; i++) {
        tcnt[t[i] - 'a']++;
        int flag = 1;
        for (int j = 0; j < 26; j++) {
            if (tcnt[j] < (cnt[j] + 1) / 2) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res = min(res, i + 1);
        }
    }
    reverse(t.begin(), t.end());
    tcnt.assign(26, 0);
    for (int i = 0; i < m; i++) {
        tcnt[t[i] - 'a']++;
        int flag = 1;
        for (int j = 0; j < 26; j++) {
            if (tcnt[j] < (cnt[j] + 1) / 2) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res = min(res, i + 1);
        }
    }
    cout << res << '\n';
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