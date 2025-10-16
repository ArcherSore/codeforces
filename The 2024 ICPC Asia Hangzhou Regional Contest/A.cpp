#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct DSU {
    vector<int> f;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }
};

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a.size() != b.size()) {
        cout << "NO\n";
        return;
    }
    DSU dsu(26);
    for (int i = 0; i < a.size(); i++) {
        dsu.merge(a[i] - 'a', b[i] - 'a');
    }
    for (char &x : a) {
        x = dsu.find(x - 'a') + 'a';
    }
    for (char &x : b) {
        x = dsu.find(x - 'a') + 'a';
    }
    for (char &x : c) {
        x = dsu.find(x - 'a') + 'a';
    }
    if (a == b && (a.size() != c.size() || a != c)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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