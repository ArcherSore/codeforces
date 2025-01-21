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

vector<int> get_fac(LL x) {
    vector<int> fac;
    for (int i = 1; i * i <= abs(x); i++) {
        if (x / i * i == x) {
            fac.push_back(i);
            fac.push_back(-i);
            if (i * i != x) {
                fac.push_back(x / i);
                fac.push_back(-x / i);
            }
        }
    }
    return fac;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<LL> a(n), b(m);
    LL suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    sort(a.begin(), a.end());
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        sumb += b[j];
    }
    sort(b.begin(), b.end());

    LL tot = suma * sumb;
    while (q--) {
        LL x;
        cin >> x;
        vector<int> fac = get_fac(x);
        int flag = false;
        for (auto &x1 : fac) {
            int x2 = x / x1;
            auto p1 = lower_bound(a.begin(), a.end(), suma - x1) - a.begin();
            auto p2 = lower_bound(b.begin(), b.end(), sumb - x2) - b.begin();

            if (p1 < n && suma == a[p1] + x1 && p2 < m && sumb == b[p2] + x2) {
                flag = true;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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