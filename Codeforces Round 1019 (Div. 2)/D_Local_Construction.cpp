#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    int l = 1, r = n, mx = *max_element(a.begin(), a.end());
    int p;
    vector<vector<int>> g(mx + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            p = i;
        } else {
            g[a[i]].push_back(i);
        }
    }
    vector<int> res(n);
    for (int i = 1; i <= mx; i++) {
        if (i % 2) {
            int tl = r - g[i].size() + 1;
            int tr = r;
            r = tl - 1;
            for (auto tp : g[i]) {
                if (tp < p) {
                    res[tp] = tr--;
                } else {
                    res[tp] = tl++;
                }
            }
        } else {
            int tl = l;
            int tr = l + g[i].size() - 1;
            l = tr + 1;
            for (auto tp : g[i]) {
                if (tp < p) {
                    res[tp] = tl++;
                } else {
                    res[tp] = tr--;
                }
            }
        }
    }
    res[p] = l;
    
    for (auto x : res) {
        cout << x << ' ';
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