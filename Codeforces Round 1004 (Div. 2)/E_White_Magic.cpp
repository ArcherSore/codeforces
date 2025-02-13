#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool check(vector<int> &v) {
    int n = v.size();
    vector<int> _min(n), _mex(n);
    _min[0] = v[0];
    for (int i = 1; i < n; i++) {
        _min[i] = min(_min[i - 1], v[i]);
    }
    int p = (v.back() == 0);
    _mex[n - 1] = p;
    map<int, int> vis;
    vis[v.back()] = 1;
    for (int i = n - 2; i >= 0; i--) {
        vis[v[i]] = 1;
        while (p < n && vis[p]) {
            p++;
        }
        _mex[i] = p;
    }

    for (int i = 0; i < n - 1; i++) {
        if (_min[i] < _mex[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int cnt0 = 0;
    for (int &x : v) {
        cin >> x;
        if (x == 0) {
            cnt0++;
        }
    }
    if (cnt0 == 0) {
        cout << n << '\n';
        return;
    }
    int flag = 1;
    vector<int> tv;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            tv.push_back(v[i]);
        } else {
            if (flag) {
                tv.push_back(v[i]);
                flag = 0;
            }
        }
    }
    if (check(tv)) {
        cout << n - cnt0 + 1 << '\n';
    } else {
        cout << n - cnt0 << '\n';
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