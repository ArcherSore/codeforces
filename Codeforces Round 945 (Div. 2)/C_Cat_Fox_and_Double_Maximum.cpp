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

vector<int> get_a(vector<int> &p, int n, int opt) {
    vector<int> a(n);
    set<int> s1, s2;
    int t1 = n, t2 = 1;
    for (int i = 0; i < n; i++) {
        if (opt == 0) {
            if (i % 2 && i < n - 1) {
                s1.insert(p[i]);
            } else {
                s2.insert(-p[i]);
            }
        } else {
            if (i && i % 2 == 0) {
                s1.insert(p[i]);
            } else {
                s2.insert(-p[i]);
            }
        }
    }
    map<int, int> mp;
    for (auto x : s1) {
        mp[x] = t1;
        t1--;
    }
    for (auto x : s2) {
        mp[-x] = t2;
        t2++;
    }
    for (int i = 0; i < n; i++) {
        a[i] = mp[p[i]] + p[i];
    }
    return a;
}

bool check(vector<int> &a, int n) {
    for (int i = 1; i < n - 1; i += 2) {
        if (a[i] <= a[i - 1] || a[i] <= a[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    a = get_a(p, n, 0);
    if (check(a, n)) {
        for (int i = 0; i < n; i++) {
            cout << a[i] - p[i] << " ";
        }
        cout << '\n';
        return;
    }
    a = get_a(p, n, 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] - p[i] << " ";
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