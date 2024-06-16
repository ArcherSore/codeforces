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

int n;

bool check(int l, int r, int num, int &ans) {
    int x = 0;
    while ((int)log2(r) > (int)log2(l)) {
        r >>= 1;
        x++;
    }
    while (l != r) {
        x += 2;
        r >>= 1, l >>= 1;
    }
    x -= 1;
    ans = l;

    return (x + 2) % 2 == num % 2 && num >= x;
}

void fill(vector<int> &a, vector<int> &b, int l, int r, int same) {
    while (l >= 0 && b[l] != same) {
        ++l;
        b[l] = b[l - 1] / 2;
    }
    while (r < n && b[r] != same) {
        --r;
        b[r] = b[r + 1] / 2;
    }
    int opt = 1; // 1->*2 0->/2
    for (int i = l + 1; i < r; i++) {
        if (opt) {
            opt ^= 1;
            b[i] = b[i - 1] * 2;
        } else {
            opt ^= 1;
            b[i] = b[i - 1] / 2;
        }
    }
}

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int fir = -1, las = -1;
    int st = -1, num = 0;
    vector<tuple<int, int, int>> seq;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            b[i] = a[i]; // fill the exist ele
            if (st == -1) {
                fir = i; // the first ele
                st = i;
                num = 0;
            } else {
                las = i; // the last ele
                if (num != 0) {
                    seq.emplace_back(st, i, num);
                }
                if (num == 0 && a[st] / 2 != a[i] && a[i] / 2 != a[st]) {
                    // adjacent eles don't fit 
                    cout << -1 << '\n';
                    return;
                }
                st = i, num = 0;
            }
        } else {
            num++;
        }
    }
    if (las == -1) {
        las = fir;
    }

    for (auto [l, r, num] : seq) {
        int same;
        if (check(min(a[l], a[r]), max(a[l], a[r]), num, same)) {
            fill(a, b, l, r, same);
        } else {
            cout << -1 << '\n';
            return;
        }
    }

    int opt = 1;
    if (fir == -1) {
        // no exist ele
        a[0] = 1, b[0] = 1;
        for (int i = 1; i < n; i++) {
            if (opt) {
                opt ^= 1;
                b[i] = b[i - 1] * 2;
            } else {
                opt ^= 1;
                b[i] = b[i - 1] / 2;
            }
        }
    } else {
        for (int i = fir - 1; i >= 0; i--) {
            if (opt) {
                opt ^= 1;
                b[i] = b[i + 1] * 2;
            } else {
                opt ^= 1;
                b[i] = b[i + 1] / 2;
            }
        }
        opt = 1;
        for (int i = las + 1; i < n; i++) {
            if (opt) {
                opt ^= 1;
                b[i] = b[i - 1] * 2;
            } else {
                opt ^= 1;
                b[i] = b[i - 1] / 2;
            }
        }
    }

    for (auto x : b) {
        cout << x << " ";
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