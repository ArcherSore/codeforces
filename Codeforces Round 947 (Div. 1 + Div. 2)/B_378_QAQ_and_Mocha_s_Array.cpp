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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int g1 = a[0], g2 = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % g1) {
            g2 = a[i];
            break;
        }
    }
    if (g2 == 0) {
        cout << "Yes\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % g1 && a[i] % g2) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
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