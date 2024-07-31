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
    vector<char> v(n + 1);

    int last = 0;
    map<int, int> next_log;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 'L') {
            next_log[last] = i;
            last = i;
            
        }
    }
    next_log[last] = n + 1;

    int p = 0;
    while (p <= n) {
        int dest = next_log[p];
        if (dest - p <= m) {
            p = dest;
        } else {
            p += m;
            while (k && p < dest) {
                if (v[p] == 'C') {
                    cout << "NO\n";
                    return;
                }
                p += 1, k -= 1;
            }
            if (p < dest) {
                cout << "NO\n";
                return;
            }
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