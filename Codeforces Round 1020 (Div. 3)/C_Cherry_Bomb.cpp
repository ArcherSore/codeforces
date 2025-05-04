#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    if (count(b.begin(), b.end(), -1) != n) {
        int st;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                st = a[i] + b[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (a[i] + b[i] != st) {
                    cout << 0 << '\n';
                    return;
                }
            } else {
                if (st - a[i] < 0 || st - a[i] > k) {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
        cout << 1 << '\n';
        return;
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    cout << max(0, mn + k - mx + 1) << '\n';
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