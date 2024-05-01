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

bool check(LL mid, LL n, LL k, vector<LL> cards) {
    LL need = 0;
    for (LL i = 1; i <= n; i++) {
        if (cards[i] < mid) {
            need += mid - cards[i];
            if (need > k) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> cards(n + 1);
    for (LL i = 1; i <= n; i++) {
        cin >> cards[i];
    }

    LL l = 0, r = 1e18, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid, n, k, cards)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    LL cnt = 0;
    for (LL i = 1; i <= n; i++) {
        if (cards[i] <= l) {
            k -= (l - cards[i]);
        } else {
            cnt++;
        }
    }
    // cout << cnt << " " << k << " " << l <<'\n'; 
    LL res = l * n - (n - 1) + cnt + k;
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