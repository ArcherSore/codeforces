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

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    if (*s.rbegin() - *s.begin() + 1 <= k) {
        cout << *s.rbegin() << '\n';
        return;
    }

    int last = *s.rbegin();
    while (*s.rbegin() - *s.begin() + 1 > k) {
        if (*s.begin() == last) {
            cout << -1 << '\n';
            return;
        }
        int fir = *s.begin(), bak = *s.rbegin();
        s.erase(s.begin());
        fir += (int)(0.5 + 1.0 * (bak - fir) / 2 / k) * 2 * k;
        s.insert(fir);
    }
    cout << *s.rbegin() << '\n';
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