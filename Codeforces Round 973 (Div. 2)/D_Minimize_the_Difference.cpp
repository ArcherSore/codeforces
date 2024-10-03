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
    vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    stack<pair<LL, int>> st;
    for (int i = 0; i < n; i++) {
        LL sum = v[i], cnt = 1;
        while (!st.empty() && st.top().first >= sum / cnt) {
            sum += st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        st.push({sum / cnt, cnt - sum % cnt});
        if (sum % cnt) {
            st.push({sum / cnt + 1, sum % cnt});
        }
    }

    LL mx = st.top().first;
    while (st.size() > 1) {
        st.pop();
    }
    LL mn = st.top().first;
    cout << mx - mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}