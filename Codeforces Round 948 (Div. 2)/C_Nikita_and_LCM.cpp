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

vector<int> get_divs(int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i) {
            continue;
        }
        res.push_back(i);
        if (i * i != x) {
            res.push_back(x / i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int res = 0;
    vector<int> divs = get_divs(a.back());
    for (int i = 0; i < n - 1; i++) {
        if (a.back() % a[i]) {
            cout << n << '\n';
            return;
        }
    }
    for (auto x : divs) {
        // cout << x << '\n';
        int tot = 0, tmp = 1;
        for (int i = 0; i < a.size() - 1; i++) {
            if (x % a[i] == 0) {
                tot++;
                tmp = lcm(tmp, a[i]);
            }
        }
        // cout << p - a.begin() << '\n';
        int flag = 1;
        for (auto ai : a) {
            if (tmp == ai) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res = max(res, tot);
        }
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