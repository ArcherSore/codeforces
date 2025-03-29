#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    while (q--) {
        int n;
        cin >> n;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int flag = 1;
        while (flag) {
            flag = 0;
            for (auto x : a) {
                if (x >= p.size()) {
                    break;
                }
                flag = 1;
                p.erase(p.begin() + x);
            }
        }
        cout << p.size() << ' ';
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