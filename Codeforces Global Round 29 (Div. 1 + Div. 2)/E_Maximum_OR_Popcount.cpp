#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    int ora = 0;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        ora |= x;
    }
    int base = 0;
    for (int i = 0; i < 31; i++) {
        if (ora >> i & 1) {
            base++;
        }
    }

    int x = ora;
    vector<int> costs = {0};
    for (int i = 0; i < 31; i++) {
        if (x >> i & 1) {
            continue;
        }
        int cost = costs.back();
        for (int j = i; j >= 0; j--) {
            int p = -1;
            int mask = (1 << j) - 1;
            bool ok = false;
            // find the closest
            for (int k = 0; k < n; k++) {
                if (a[k] >> j & 1) {
                    ok = true;
                    break;
                }
                if (p == -1 || (a[k] & mask) > (a[p] & mask)) {
                    p = k;
                }
            }
            if (ok) {
                continue;
            }
            // update a[i]
            cost += (1 << j) - (a[p] & mask);
            a[p] &= ~mask;
            a[p] |= (1 << j);
        }
        costs.push_back(cost);
    }

    while (q--) {
        int b;
        cin >> b;
        int p = 0;
        while (p + 1 < costs.size() && costs[p + 1] <= b) {
            p++;
        }
        cout << base + p << '\n';
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