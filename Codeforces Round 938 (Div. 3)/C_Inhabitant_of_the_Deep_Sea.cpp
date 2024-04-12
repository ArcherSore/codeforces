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
    LL n, k;
    cin >> n >> k;
    deque<LL> q;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        q.push_back(x);
    }

    LL res = 0;
    while (!q.empty()) {
        if (q.size() == 1) {
            if (k >= q.front()) {
                res ++;
            }
            break;
        }
        LL a = q.front(), b = q.back();
        if (2 * min(a, b) > k) {
            if (a <= b && a <= (k + 1) / 2 || a > b && b <= k / 2) {
                res += 1;
            }
            break;
        }
        k -= 2 * min(a, b);
        if (a > b) {
            q.front() -= b;
            q.pop_back();
            res++;
        } else if (a < b) {
            q.back() -= a;
            q.pop_front();
            res++;
        } else {
            q.pop_back(), q.pop_front();
            res += 2;
        }
    }

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