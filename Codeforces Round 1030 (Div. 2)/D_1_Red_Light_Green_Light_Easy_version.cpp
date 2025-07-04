#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct State {
    int id, dir, time;
};

void solve() {
    int n, k, q;
    cin >> n >> k;
    vector<LL> p(n);
    for (auto &x : p) {
        cin >> x;
    }
    vector<int> d(n);
    for (auto &x : d) {
        cin >> x;
    }
    cin >> q;
    while (q--) {
        LL st;
        cin >> st;
        auto it = lower_bound(p.begin(), p.end(), st);
        if (it == p.end()) {
            cout << "YES\n";
            continue;
        }

        State s = {(int)(it - p.begin()), 1, ((*it) - st) % k};
        int res = -1;
        vector<vector<int>> vis(n, vector<int> (2, 0));
        while (true) {
            if (s.time == d[s.id]) {
                s.dir ^= 1;
                if (vis[s.id][s.dir]) {
                    res = 0;
                    break;
                }
                vis[s.id][s.dir] = 1;
            }

            if (s.dir) {
                s.id++;
                if (s.id == n) {
                    res = 1;
                    break;
                }
                s.time = (s.time + p[s.id] - p[s.id - 1]) % k;
            } else {
                s.id--;
                if (s.id < 0) {
                    res = 1;
                    break;
                }
                s.time = (s.time + p[s.id + 1] - p[s.id]) % k;
            }
        }
        cout << (res ? "YES\n" : "NO\n");
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