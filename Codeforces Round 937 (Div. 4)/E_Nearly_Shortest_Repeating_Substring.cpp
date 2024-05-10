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

vector<int> get_fac(int x) {
    vector<int> fac;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i == x) {
                fac.push_back(i);
            } else {
                fac.push_back(i);
                fac.push_back(x / i);
            }
        }
    }
    return fac;
}

bool one_dif(string &s1, string &s2) {
    int dif = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            dif ++;
        }
        if (dif > 1) {
            return false;
        }
    }
    return true;
}

bool check(int len, string &s) {
    int n = s.size(), cnt = 0;
    string lib, t1, t2;
    lib = s.substr(0, len);
    for (int i = 0; i < n / len; i++) {
        t1 += lib;
    }
    if (one_dif(s, t1)) {
        return true;
    }
    lib = s.substr(len, len);
    for (int i = 0; i < n / len; i++) {
        t2 += lib;
    }
    if (one_dif(s, t2)) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> fac = get_fac(n);
    sort(fac.begin(), fac.end());
    // for (auto x : fac) {
    //     cout << x << '\n';
    // }
    string s;
    cin >> s;
    for (auto l : fac) {
        if (check(l, s)) {
            cout << l << '\n';
            return;
        }
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