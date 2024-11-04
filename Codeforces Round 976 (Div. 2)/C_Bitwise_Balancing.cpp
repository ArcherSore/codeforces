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

map<tuple<int, int, int>, int> mp;

void init() {
    mp[{1, 1, 1}] = 0;
    mp[{1, 1, 0}] = 1;
    mp[{1, 0, 1}] = 1;
    mp[{1, 0, 0}] = -1;
    mp[{0, 1, 1}] = -1;
    mp[{0, 1, 0}] = 1;
    mp[{0, 0, 1}] = 1;
    mp[{0, 0, 0}] = 0;
}

vector<int> get_fac(LL x) {
    vector<int> fac;
    while (x) {
        fac.push_back(x & 1);
        x >>= 1;
    }
    return fac;
} 

void solve() {
    LL b, c, d;
    cin >> b >> c >> d;
    vector<int> B = get_fac(b);
    vector<int> C = get_fac(c);
    vector<int> D = get_fac(d);

    int size = max(B.size(), max(C.size(), D.size()));
    while (B.size() < size) {
        B.push_back(0);
    }
    while (C.size() < size) {
        C.push_back(0);
    }
    while (D.size() < size) {
        D.push_back(0);
    }

    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    reverse(D.begin(), D.end());

    LL ans = 0;
    for (int i = 0; i < size; i++) {
        // cout << B[i] << ' ' << C[i] << ' ' << D[i] << ' ' << mp[{B[i], C[i], D[i]}] << '\n';
        if (mp[{B[i], C[i], D[i]}] == -1) {
            cout << -1 << '\n';
            return;
        }
        ans |= mp[{B[i], C[i], D[i]}];
        ans <<= 1;
    }
    ans >>= 1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}