#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), cnt(n + 1);
    for (auto &x : v) {
        cin >> x;
        cnt[x]++;
    }

    int res = 0, length = 0;
    int st;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (cnt[v[i]] == 1) {
            if (length == 0) {
                st = i;
            }
            length += 1;
        } else {
            if (length > res) {
                l = st + 1, r = i;
                res = length;
            }
            length = 0;
        }
    }
    if (length > res) {
        l = st + 1, r = n;
        length = res;
    }
    if (l == -1 && r == -1) {
        cout << 0 << '\n';
    } else {
        cout << l << ' ' << r << '\n';
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