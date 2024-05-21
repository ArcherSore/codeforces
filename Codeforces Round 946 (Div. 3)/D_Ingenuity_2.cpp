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

bool check(int a, int b) {
    if (a == 0 && b != 0 && b % 2 || a != 0 && b == 0 && a % 2) {
        return false;
    }
    if (a != 0 && b != 0 && a != b) {
        if (abs(a - b) % 2) {
            return false;
        }
    }
    return true;
}

bool check1(string &s, int n) {
    int num = 0;
    for (auto c : s) {
        if (c == 'R') {
            num++;
        }
    }
    return num > 0 && num < n;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int N = 0, S = 0, E = 0, W = 0;
    for (auto c : s) {
        if (c == 'N') N++;
        if (c == 'S') S++;
        if (c == 'E') E++;
        if (c == 'W') W++;
    }

    if (!check(N, S) || !check(E, W)) {
        cout << "NO\n";
        return;
    }

    int rn = abs(N - S) / 2, rs = 0, re = abs(E - W) / 2, rw = 0;
    if (N > S) {
        rn = (N - S) / 2, rs = 0;
    } else if (N == S) {
        rn = N / 2, rs = rn;
    } else {
        rs = (S - N) / 2, rn = 0;
    }
    if (E > W) {
        re = (E - W) / 2, rw = 0;
    } else if (E == W) {
        re = E / 2, rw = re;
    } else {
        rw = (W - E) / 2, re = 0;
    }
    re = E - re, rw = W - rw;
    string res;
    for (auto c : s) {
        if (c == 'N') {
            if (rn > 0) {
                res.push_back('R');
            } else {
                res.push_back('H');
            }
            rn--;
        }
        if (c == 'S') {
            if (rs > 0) {
                res.push_back('R');
            } else {
                res.push_back('H');
            }
            rs--;
        }
        if (c == 'E') {
            if (re > 0) {
                res.push_back('R');
            } else {
                res.push_back('H');
            }
            re--;
        }
        if (c == 'W') {
            if (rw > 0) {
                res.push_back('R');
            } else {
                res.push_back('H');
            }
            rw--;
        }
    }
    if (!check1(res, n)) {
        cout << "NO\n";
    } else {
        cout << res << '\n';
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