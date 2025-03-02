#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<LL> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    LL l = 0, r = 1e9, mid;
    auto check = [&]() -> bool {
        vector<char> v;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                v.push_back(s[i]);
            }
        }
        if (v.empty()) {
            return true;
        }
        int cnt = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] != v[i - 1]) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            cnt /= 2;
        } else {
            cnt /= 2;
            if (v[0] == 'B') {
                cnt += 1;
            }
        }
        return cnt <= k;
    };
    while (l < r) {
        mid = (l + r) / 2;
        if (check()) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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