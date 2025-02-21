#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    vector<int> res;
    for (auto [x, c] : cnt) {
        if (c > 1) {
            res.push_back(x);
        }
    }
    if (res.size() == 0) {
        cout << -1 << '\n';
        return;
    } else if (res.size() > 1) {
        cout << res[0] << ' ' << res[0] << ' ' << res[1] << ' ' << res[1] << '\n';
        return;
    }
    
    n -= 2;
    vector<int> v;
    for (auto [x, c] : cnt) {
        if (c == 1) {
            v.push_back(x);
        } else {
            int t = c;
            while (t > 2) {
                v.push_back(x);
                t--;
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        int x = 2 * res[0] + v[i];
        int l = 0, r = n - 1, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (v[mid] < x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l >= i + 1) {
            cout << res[0] << ' ' << res[0] << ' ' << v[i] << ' ' << v[l] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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