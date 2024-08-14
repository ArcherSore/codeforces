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

bool check(vector<int> &a, vector<int> &b, int mid, int n, int k) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < mid) {
            continue;
        }
        tot += (a[i] - mid) / b[i] + 1;
        if (tot > k) {
            return false;
        }
    }
    return true;;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    } 
    
    int l = 1, r = 1e9 + 1, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(a, b, mid, n, k)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    priority_queue<PII> st;
    int _std = l;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < _std) {
            st.emplace(a[i], b[i]);
            continue;
        }
        int opt = (a[i] - _std) / b[i] + 1;
        ans += 1LL * ((2 * a[i]) -  b[i] * (opt - 1)) * opt / 2;
        k -= opt;
        st.emplace(max(0, a[i] - b[i] * opt), b[i]);
    }

    while (k--) {
        auto [aa, bb] = st.top();
        st.pop();

        if (aa == 0) {
            break;
        }

        ans += 1LL * aa;
        st.emplace(max(0, aa - bb), bb);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}