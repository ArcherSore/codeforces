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
    vector<LL> v(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    vector<char> opt(n + 1);
    priority_queue<int, vector<int>, greater<int>> l;
    priority_queue<int> r;
    for (int i = 1; i <= n; i++) {
        cin >> opt[i];
        if (opt[i] == 'L') {
            l.push(i);
        } else {
            r.push(i);
        }
    }

    LL ans = 0;
    while (!l.empty() && !r.empty()) {
        int ll = l.top(), rr = r.top();
        l.pop(), r.pop();

        if (ll > rr) {
            break;
        }
        ans += 1LL * (sum[rr] - sum[ll - 1]);
    }
    cout << ans << '\n';
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