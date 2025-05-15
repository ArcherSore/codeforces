#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e18;

LL work(vector<LL> &t) {
    LL mx = t[0], sum = t[0];
    for (int i = 1; i < t.size(); i++) {
        sum = max(t[i], sum + t[i]);
        mx = max(mx, sum);
    }
    return mx;
}

void solve() {
    int n;
    LL k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<LL> v(n);
    for (auto &x : v) {
        cin >> x;
    }

    int lst = -1;
    LL tmx = -INF;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (lst != -1) {
                vector<LL> t(v.begin() + lst, v.begin() + i);
                tmx = max(tmx, work(t));
            }
            lst = -1;
        } else {
            if (lst == -1) {
                lst = i;
            }
        }
    }
    if (lst != -1) {
        vector<LL> t(v.begin() + lst, v.end());
        tmx = max(tmx, work(t));
    }
    if (tmx > k) {
        cout << "No\n";
        return;
    }
    if (count(s.begin(), s.end(), '1') == n) {
        if (tmx != k) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (auto x : v) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        return;
    }

    auto le = [&](int ii) -> LL {
        LL mx = 0, sum = 0;
        for (int i = ii - 1; i >= 0 && s[i] != '0'; i--) {
            sum += v[i];
            mx = max(sum, mx);
        }
        return mx;
    };

    auto ri = [&](int ii) -> LL {
        LL mx = 0, sum = 0;
        for (int i = ii + 1; i < n && s[i] != '0'; i++) {
            sum += v[i];
            mx = max(sum, mx);
        }
        return mx;
    };

    LL mx = -INF, pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            LL left = le(i), right = ri(i);
            if (left + right > mx) {
                mx = left + right;
                pos = i;
            }
        }
    }
    if (pos != -1) {
        v[pos] = k - mx;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && i != pos) {
            v[i] = -INF;
        }
    }
    cout << "Yes\n";
    for (auto x : v) {
        cout << x << ' ';
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