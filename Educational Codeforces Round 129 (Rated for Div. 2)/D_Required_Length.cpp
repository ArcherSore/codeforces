#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using u64 = unsigned long long;
using PII = pair<int, int>;

const u64 INF = 1e19;

int len(u64 x) {
    int cnt = 0;
    while (x) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

vector<int> digit(u64 x) {
    vector<int> vis(10);
    while (x) {
        int d = x % 10;
        vis[d] = 1;
        x /= 10;
    }
    return vis;
}

void solve() {
    u64 n, x;
    cin >> n >> x;

    int flag = 0;
    vector<int> t = digit(x);
    for (int i = 2; i < 10; i++) {
        if (t[i]) {
            flag = 1;
        }
    }
    if (!flag) {
        cout << -1;
        return;
    }

    queue<pair<u64, int>> q;
    q.push({x, 0});
    set<u64> s;
    s.insert(x);
    while (!q.empty()) {
        u64 u = q.front().first;
        int step = q.front().second;
        q.pop();

        vector<int> d = digit(u);
        for (int i = 2; i <= 9; i++) {
            if (d[i]) {
                if (u > INF / i) {
                    cout << step + 1;
                    return;
                } else {
                    if (len(u * i) >= n) {
                        cout << step + 1;
                        return;
                    }
                    if (s.find(u * i) == s.end()) {
                        q.push({u * i, step + 1});
                        s.insert(u * i);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}