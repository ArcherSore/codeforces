#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    LL suma = 0, sumb = 0;
    map<int, int> a;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        suma += x;
        a[x]++;
    }
    vector<int> b(m);
    for (auto &x : b) {
        cin >> x;
        sumb += x;
    }
    if (suma != sumb) {
        cout << "No\n";
        return;
    }

    auto breakdown = [&](auto &self, int x) -> bool {
        if (a.empty() || x < (*a.begin()).first) {
            return false;
        }
        if (a.find(x) != a.end()) {
            a[x]--;
            if (a[x] == 0) {
                a.erase(x);
            }
            return true;
        }
        int x1 = (x + 1) / 2, x2 = x / 2;
        if (!self(self, x1)) {
            return false;
        }
        if (!self(self, x2)) {
            return false;
        }
        return true;
    };
    for (auto x : b) {
        if (!breakdown(breakdown, x)) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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