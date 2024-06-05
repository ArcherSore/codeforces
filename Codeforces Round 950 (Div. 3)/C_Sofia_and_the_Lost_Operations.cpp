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
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> modify;
    set<int> ss;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ss.insert(b[i]);
        if (a[i] != b[i]) {
            modify[b[i]]++;
        }
    }
    cin >> m;
    int last;
    map<int, int> has;
    for (int i= 0; i < m; i++) {
        int x;
        cin >> x;
        has[x]++;
        if (i == m - 1) {
            last = x;
        }
    }

    for (auto [x, num] : modify) {
        if (has[x] < num) {
            cout << "NO\n";
            return;
        }
    }

    if (ss.find(last) == ss.end()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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