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

int parity(vector<int> &a) {
    int n = a.size();
    vector<int> vis(n);
    int p = n % 2;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }

        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = 1;
        }
        p ^= 1;
    }
    return p;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> t1 = a, t2 = b;
    sort(t1.begin() , t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(t1.begin() , t1.end(), a[i]) - t1.begin();
    }
    for (int i = 0; i < n; i++) {
        b[i] = lower_bound(t2.begin(), t2.end(), b[i]) - t2.begin();
    }

    // cout << parity(a) << " " << parity(b) << '\n';

    if (parity(a) == parity(b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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