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

PII work(vector<int> &a) {
    int tmp = 0, min_pre = 0, max_pre = 0;
    int min_ssum = 0, max_ssum = 0;
    for (int x : a) {
        tmp += x;
        min_ssum = min(min_ssum, tmp - max_pre);
        max_ssum = max(max_ssum, tmp - min_pre);

        min_pre = min(min_pre, tmp);
        max_pre = max(max_pre, tmp);
    }
    return {min(min_ssum, 0), max(max_ssum, 0)};
}

PII cal(vector<int> &a) {
    int l = 0, r = 0;
    int tmp = 0;
    for (int x : a) {
        tmp += x;
        l = min(l, tmp);
        r = max(r, tmp);
    }
    return {l, r};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1 && a[i] != 1) {
            p = i;
        }
    }
    if (p == -1) {
        auto [l, r] = work(a);
        cout << r - l + 1 << '\n';
        for (int i = l; i <= r; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    
    set<int> ans;
    vector<int> pre, sub;
    for (int i = p - 1; i >= 0; i--) {
        pre.push_back(a[i]);
    }
    PII seg = work(pre);
    for (int i = seg.first; i <= seg.second; i++) {
        ans.insert(i);
    }
    for (int i = p + 1; i < n; i++) {
        sub.push_back(a[i]);
    }
    seg = work(sub);
    for (int i = seg.first; i <= seg.second; i++) {
        ans.insert(i);
    }

    PII seg1 = cal(pre), seg2 = cal(sub);
    seg.first = seg1.first + seg2.first;
    seg.second = seg1.second + seg2.second;
    for (int i = a[p] + seg.first; i <= a[p] + seg.second; i++) {
        ans.insert(i);
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
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