#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    for (auto &x : b) {
        cin >> x;
        x--;
    }

    vector<PII> res;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (i != n / 2) {
                swap(a[i], a[n / 2]);
                swap(b[i], b[n / 2]);
                res.push_back({i, n / 2});
            }
            break;
        }
    }

    int same = 0;
    vector<int> mp(n), pos(n);
    for (int i = 0; i < n; i++) {
        mp[a[i]] = b[i];
        pos[a[i]] = i;
        if (a[i] == b[i]) {
            same++;
        }
    }
    if (n % 2 == 0 && same > 0 || n % 2 && same > 1) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mp[mp[i]] != i) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i + pos[mp[a[i]]] == n - 1) {
            continue;
        }
        int l = pos[mp[a[i]]], r = n - i - 1;
        res.push_back({l, r});
        swap(a[l], a[r]);
        swap(b[l], b[r]);
        swap(pos[a[l]], pos[a[r]]);
    }

    cout << res.size() << '\n';
    for (auto [l, r] : res) {
        cout << l + 1 << ' ' << r + 1 << '\n';
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