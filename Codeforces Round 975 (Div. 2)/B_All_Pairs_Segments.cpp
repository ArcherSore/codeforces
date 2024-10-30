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
    int n, q;
    cin >> n >> q;

    vector<LL> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    vector<LL> k(q);
    for (int i = 0; i < q; i++) {
        cin >> k[i];
    }

    LL tmp = n - 1;
    map<LL, LL> cnt;
    cnt[tmp] = 1;
    for (int i = 1; i < n; i++) {
        cnt[i * tmp] += x[i] - x[i - 1] - 1;
        cnt[i * tmp + tmp - 1] += 1;
        tmp -= 1;
    }

    for (int i = 0; i < q; i++) {
        if (cnt.find(k[i]) != cnt.end()) {
            cout << cnt[k[i]] << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';
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