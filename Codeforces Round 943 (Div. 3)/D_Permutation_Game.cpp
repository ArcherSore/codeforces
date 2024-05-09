// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct Status {
    int pos, lvl;
    LL score;
};

LL bfs(int pos, int k, vector<int> p, vector<int> a, int maxa) {
    int n = a.size();
    queue<Status> q;
    vector<int> vis(n);
    q.push({pos, 1, 0});
    LL res = 0;
    while (!q.empty()) {
        auto [pos, lvl, score] = q.front();
        q.pop();
        if (lvl > k) {
            res = max(res, score);
            break;
        }
        res = max(res, score + 1LL * a[pos] * (k - lvl + 1));
        if (vis[pos] || a[pos] == maxa || p[pos] == pos) {
            break;
        }
        vis[pos] = 1;
        q.push({p[pos], lvl + 1, score + 1LL * a[pos]});
    }
    return res;
}

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    int maxa = 0;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(a[i], maxa);
    }

    LL ansb = bfs(pb, k, p, a, maxa);
    LL anss = bfs(ps, k, p, a, maxa);
    if (ansb > anss) {
        cout << "Bodya\n";
    } else if (ansb < anss) {
        cout << "Sasha\n";
    } else {
        cout << "Draw\n";
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