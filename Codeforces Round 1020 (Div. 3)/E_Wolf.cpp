#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        if (pos[k] < l || pos[k] > r) {
            cout << -1 << ' ';
            continue;
        }
        int le = l, ri = r, mid;
        int less = 0, more = 0;
        int less_u = 0, more_u = 0;
        int res = -1;
        while (le <= ri) {
            mid = (le + ri) / 2;
            if (mid < pos[k]) {
                le = mid + 1;
                if (p[mid] > k) {
                    less++;
                } else {
                    less_u++;
                }
            } else if (mid > pos[k]) {
                ri = mid - 1;
                if (p[mid] < k) {
                    more++;
                } else {
                    more_u++;
                }
            } else {
                res = mid;
                break;
            }
        }
        // cout << less << ' ' << more << '\n';
        // cout << less_u << ' ' << more_u << '\n';
        if (res == -1) {
            cout << -1 << ' ';
            continue;
        }
        if (less >= more) {
            if (less >= k - less_u) {
                cout << -1 << ' ';
            } else {
                cout << 2 * less << ' ';
            }
        } else {
            if (more > n - k - more_u) {
                cout << -1 << ' ';
            } else {
                cout << 2 * more << ' ';
            }
        }
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