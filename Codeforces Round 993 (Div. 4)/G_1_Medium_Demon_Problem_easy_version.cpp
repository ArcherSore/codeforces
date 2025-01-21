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
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        cin >> to[i];
        to[i]--;
    }

    vector<int> d(n, -1);
    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            continue;
        }
        int cur = i;
        vector<int> s;
        while (d[cur] == -1) {
            s.push_back(cur);
            d[cur] = 0;
            cur = to[cur];
        }
        auto it = find(s.begin(), s.end(), cur);
        s.erase(it, s.end());
        for (int k = 0; k < s.size(); k++) {
            d[s[k]] = d[cur] + s.size() - k;
        }
    }

    int ans = *max_element(d.begin(), d.end());
    cout << ans + 2 << '\n';
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