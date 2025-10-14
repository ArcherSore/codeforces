#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int M = 1e5;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    bitset<M> bs;
    vector<pair<int, ll>> res(m);
    for (int i = 0; i < m; i++) {
        res[i].first = i + 1;
    }
    int cur = 0, scr = m;
    while (q--) {
        int opt, id, x;
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            bs.reset();
            cur = x;
            scr = m;
        } else if (opt == 2) {
            cin >> id >> x;
            id--;
            if (x != cur || bs[id]) {
                continue;
            }
            bs.set(id);
            res[id].second += scr;
            scr--;
        } else {
            cin >> id >> x;
            id--;
            if (x != cur || bs[id]) {
                continue;
            }
            bs.set(id);
        }
    }
    sort(res.begin(), res.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    for (auto [idx, x] : res) {
        cout << idx << ' ' << x << '\n';
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