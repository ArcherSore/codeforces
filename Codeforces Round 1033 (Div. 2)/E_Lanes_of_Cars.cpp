#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int mid) -> bool {
        LL need = 0, extra = 0;
        for (int i = 0; i < n; i++) {
            need += max(0, mid - a[i]);
            extra += max(0, a[i] - (mid + k));
        }
        return need <= extra;
    };
    int le = 1, ri = *max_element(a.begin(), a.end()), mid;
    int best = -1;
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (check(mid)) {
            best = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }

    // debug
    // cout << best << '\n';

    LL need = 0, extra = 0;
    for (int i = 0; i < n; i++) {
        need += max(0, best - a[i]);
        extra += max(0, a[i] - (best + k));
    }
    LL rest = extra - need;

    for (auto &x : a) {
        if (x < best) {
            x = best;
        } else if (x > best + k) {
            x = best + k;
        }
    }
    sort(a.begin(), a.end());
    
    int cnt = count(a.begin(), a.end(), best);
    if (cnt >= rest) {
        for (int i = 0; i < rest; i++) {
            a[i]++;
        }
        rest = 0;
    } else {
        for (int i = 0; i < cnt; i++) {
            a[i]++;
        }
        rest -= cnt;
        for (int i = n - 1; i >= n - rest; i--) {
            a[i]++;
        }
    }


    // debug
    // sort(a.begin(), a.end());
    // for (auto x : a) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    LL res = (extra - rest) * k;
    for (auto x : a) {
        res += 1LL * x * (x + 1) / 2;
    }
    cout << res << '\n';
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