#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i - 1]) <= 1) {
            cout << 0 << '\n';
            return;
        }
    }
    int res = n;
    for (int i = 0; i < n - 2; i++) {
        if (v[i + 1] > v[i]) {
            for (int j = i + 2; j < n; j++) {
                if (v[j] <= v[i]) {
                    res = min(res, j - i - 1);
                    break;
                }
            }
        } else {
            for (int j = i + 2; j < n; j++) {
                if (v[j] >= v[i]) {
                    res = min(res, j - i - 1);
                    break;
                }
            }
        }
    }
    for (int i = n - 1; i >= 2; i--) {
        if (v[i - 1] > v[i]) {
            for (int j = i - 2; j >= 0; j--){
                if (v[j] <= v[i]) {
                    res = min(res, i - 1 - j);
                    break;
                }
            }
        } else {
            for (int j = i - 2; j >= 0; j--){
                if (v[j] >= v[i]) {
                    res = min(res, i - 1 - j);
                    break;
                }
            }
        }
    }

    cout << (res == n ? -1 : res) << '\n';
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