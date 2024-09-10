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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] -= i;
    }

    map<int, int> cnt;
    map<int, set<int>, greater<int>> max_ele; 
    for (int i = 0; i < k; i++) {
        if (cnt.find(v[i]) != cnt.end() && max_ele.find(cnt[v[i]]) != max_ele.end()) {
            max_ele[cnt[v[i]]].erase(v[i]);
            if (max_ele[cnt[v[i]]].empty()) {
                max_ele.erase(cnt[v[i]]);
            }
        }
        cnt[v[i]]++;
        max_ele[cnt[v[i]]].insert(v[i]);
    }
    
    vector<int> res(n);
    res[0] = k - (*max_ele.begin()).first;
    for (int i = 1; i < n - k + 1; i++) {
        // l
        max_ele[cnt[v[i - 1]]].erase(v[i - 1]);
        if (max_ele[cnt[v[i - 1]]].empty()) {
            max_ele.erase(cnt[v[i - 1]]);
        }
        cnt[v[i - 1]]--;
        if (cnt[v[i - 1]]) {
            max_ele[cnt[v[i - 1]]].insert(v[i - 1]);
        }
        // r
        max_ele[cnt[v[i + k - 1]]].erase(v[i + k - 1]);
        if (max_ele[cnt[v[i + k - 1]]].empty()) {
            max_ele.erase(cnt[v[i + k - 1]]);
        }
        cnt[v[i + k - 1]]++;
        max_ele[cnt[v[i + k - 1]]].insert(v[i + k - 1]);
        // get ans
        res[i] = k - (*max_ele.begin()).first;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << res[l] << '\n';
    }
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