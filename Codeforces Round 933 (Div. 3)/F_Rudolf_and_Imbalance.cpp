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

int get_sec_max(vector<PII> &a) {
    int res = a[0].first;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].first != a[i - 1].first) {
            res = a[i].first;
            break;
        }
    }
    return res;
}

int work(double mid, vector<int> &d, vector<int> &f) {
    set<double> std;
    for (auto x : f) {
        if (mid - 1.0 * x < 0) {
            continue;
        }
        std.insert(mid - 1.0 * x);
    }
    for (auto x : d) {
        int p = *std.lower_bound(1.0 * x);
        if (p < 0) {
            
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(m), f(k);
    vector<PII> tmp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            tmp.emplace_back(a[i] - a[i - 1], i - 1);
        }
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < k; i++) {
        cin >> f[i];
    }

    int fir = tmp[0].first, sec = get_sec_max(tmp);
    if (sec == fir) {
        cout << fir << '\n';
        return;
    }
    int i = 0, res = fir;
    while (tmp[i].first == fir) {
        int dif = tmp[i].first;
        int tt = work(1.0 * (a[tmp[i].second] + a[tmp[i].second + 1]) / 2, d, f);
        res = min(res, max(tt, dif - tt));
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