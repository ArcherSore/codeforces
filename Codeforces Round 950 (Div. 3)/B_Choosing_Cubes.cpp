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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tt = a[m - 1];
    sort(a.begin(), a.end(), greater<int> ());

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == tt && l == -1) {
            l = i;
        } 
        if (a[i] != tt && l != -1 && r == -1) {
            r = i - 1;
        }
    }
    if (r == -1) {
        r = n - 1;
    }
    // cout << l << " " << r << '\n';
    k -= 1;
    if (r <= k) {
        cout << "YES\n";
    } else if (l > k) {
        cout << "NO\n";
    } else {
        cout << "MAYBE\n";
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