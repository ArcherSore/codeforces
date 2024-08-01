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

void work(string &s, int n, int k, int p, int need) {
    if (need < 0) {
        cout << -1 << '\n';
        return;
    }
    if (s[p] != s[n - 1]) {
        need = k - need;
    }
    // cout << "need = " << need << '\n'; 

    string tmp = s.substr(0, p + need);
    reverse(tmp.begin(), tmp.end());
    s += tmp;

    int cnt = 1, last = p + need;
    for (int i = p + need + 1; s[i]; i++) {
        if (s[i] == s[last]) {
            cnt++;
        } else {
            last = i;
            if (cnt != k) {
                cout << -1 << '\n';
                return;
            }
            cnt = 1;
        }
    }
    if (cnt > 1 && cnt != k) {
        cout << -1 << '\n';
    } else {
        cout << p + need << '\n';
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int p = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != s[n - 1]) {
            p = i + 1;
            break;
        }
    }
    // all the same
    if (p == 0) {
        cout << (n == k ? n : -1) << '\n';
        return;
    }

    int cnt = 1, last = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[last]) {
            cnt++;
        } else {
            if (cnt != k) {
                work(s, n, k, last, k - n + p);
                return;
            }
            last = i;
            cnt = 1;
        }
    }
    if (cnt > 1 && cnt != k) {
        work(s, n, k, last, k - n + p);
    } else {
        cout << n << '\n';
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