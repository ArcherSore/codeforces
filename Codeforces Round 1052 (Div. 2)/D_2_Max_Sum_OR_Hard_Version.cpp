#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int L, R;
    cin >> L >> R;
    int n = R - L + 1;
    vector<int> vis(n), res(n, -1);
    auto work = [&](auto &&self, int l, int r, int offset) -> void {
        for (int i = __lg(r); i >= __lg(max(1, l)); i--) {
            int mask = (1 << i + 1) - 1;
            for (int j = max(l, 1 << i); j <= min(r, mask); j++) {
                if ((mask ^ j) + offset >= L && !vis[(mask ^ j) - L + offset] && !vis[j - L + offset]) {
                    vis[(mask ^ j) - L + offset] = 1;
                    vis[j - L + offset] = 1;
                    res[(mask ^ j) - L + offset] = j + offset;
                    res[j - L + offset] = mask ^ j + offset;
                } else if (vis[j - L + offset]) {
                    break;
                } else {
                    self(self, j - (1 << i), min(r, mask) - (1 << i), offset + (1 << i));
                }
            }
        }
    };
    work(work, L, R, 0);
    for (int i = 0; i < n; i++) {
        if (res[i] == -1) {
            res[i] = i + L;
        }
    }
    ll sum = 0;
    for (int i = L; i <= R; i++) {
        sum += i | res[i - L];
    }
    cout << sum << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("out.txt", "w", stdout);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}