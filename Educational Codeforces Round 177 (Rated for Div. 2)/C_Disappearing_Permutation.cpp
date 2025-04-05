#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for (auto &x : p) {
        cin >> x;
        x--;
    }
    for (auto &x : d) {
        cin >> x;
        x--;
    }

    int cnt = 0;
    vector<int> bel(n, -1);
    vector<int> siz;
    for (int i = 0; i < n; i++) {
        if (bel[i] != -1) {
            continue;
        }
        bel[i] = cnt;
        siz.push_back(1);
        int x = p[i];
        while (x != i) {
            bel[x] = cnt;
            siz.back() += 1;
            x = p[x];
        }
        cnt++;
    }

    LL res = 0;
    vector<int> vis(cnt);
    for (int i = 0; i < n; i++) {
        if (!vis[bel[d[i]]]) {
            res += siz[bel[d[i]]];
            vis[bel[d[i]]] = 1;
        }
        cout << res << ' ';
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