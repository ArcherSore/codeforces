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
    int n;
    cin >> n;
    vector<int> v(n), seat(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }

    for (int i = 0; i < n; i++) {
        seat[v[i]] = 1;
        if (i) {
            if (v[i] - 1 >= 0 && seat[v[i] - 1] || v[i] + 1 < n && seat[v[i] + 1]) {
                continue;
            }
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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