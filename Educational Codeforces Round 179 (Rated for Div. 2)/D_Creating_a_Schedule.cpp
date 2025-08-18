#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cls;
    map<int, vector<int>> act;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        cls[x / 100]++;
        act[x / 100].push_back(x);
    }
    int cnt = 0;
    vector<int> res;
    while (cls.size() >= 2 && cnt < n - 1) {
        auto &[flr1, cnt1] = *cls.begin();
        auto &[flr2, cnt2] = *cls.rbegin();
        int mn = min(cnt1, cnt2);
        // res += abs(flr1 - flr2) * 5 * min((n - cnt) / 2, mn) * 2;
        for (int i = 0; i < min((n - cnt) / 2, mn); i++) {
            res.push_back(act[flr1].back());
            act[flr1].pop_back();
            res.push_back(act[flr2].back());
            act[flr2].pop_back();
        }
        cnt1 -= min((n - cnt) / 2, mn), cnt2 -= min((n - cnt) / 2, mn);
        cnt += min((n - cnt) / 2, mn) * 2;
        if (cnt1 == 0) {
            cls.erase(cls.begin());
        }
        if (cnt2 == 0) {
            cls.erase(prev(cls.end()));
        }
    }
    if (cls.size() == 1) {
        while (res.size() < n - 1) {
            auto [flr1, cnt1] = *cls.begin();
            res.push_back(act[flr1].back());
            act[flr1].pop_back();
            res.push_back(act[flr1].back());
            act[flr1].pop_back();
            cnt1 -= 2;
        }
    }
    // output
    for (int j = 0; j < res.size(); j += 2) {
        for (int i = 0; i < 6; i++) {
            if (i % 2) {
                cout << res[j] << ' ';
            } else {
                cout << res[j + 1] << ' ';
            }
        }
        cout << '\n';
        for (int i = 0; i < 6; i++) {
            if (i % 2) {
                cout << res[j + 1] << ' ';
            } else {
                cout << res[j] << ' ';
            }
        }
        cout << '\n';
    }

    if (res.size() < n) {
        if (cls.size() == 1) {
            auto [flr1, cnt1] = *cls.begin();
            for (int i = 0; i < 6; i++) {
                cout << act[flr1].back() << ' ';
            }
        } else {
            auto [flr1, cnt1] = *cls.begin();
            auto [flr2, cnt2] = *cls.rbegin();
            for (int i = 0; i < 6; i += 2) {
                cout << act[flr1].back() << ' ' << act[flr2].back() << ' ';
            }
        }
        cout << '\n';
    }
    // cout << res << '\n'; 
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