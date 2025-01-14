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
    int n, k, l;
    cin >> n >> k >> l;
    k *= 2, l *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
    
    int t = a[0], crow = k;
    for (int i = 1; i < n; i++) {
        if (a[i] >= crow) {
            int new_pos = max(crow, a[i] - t);
            t += (new_pos - crow) / 2;
            crow = (new_pos + crow) / 2 + k;
        } else {
            int new_pos = min(crow, a[i] + t);
            crow = new_pos + k;
        }
    }
    if (crow < l) {
        t += l - crow;
    }
    cout << t << '\n';
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