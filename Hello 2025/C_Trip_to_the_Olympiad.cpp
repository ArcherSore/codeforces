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

vector<int> fac(int x) {
    vector<int> f;
    while (x) {
        f.push_back(x & 1);
        x >>= 1;
    }
    return f;
}

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> f1, f2;
    f1 = fac(l), f2 = fac(r);
    int n = f1.size(), m = f2.size();

    if (n == m) {
        int p = -1, mid = 0;
        for (int i = n - 1; i; i--) {
            if (f1[i] != f2[i]) {
                p = i;
                break;
            }
            mid |= f1[i];
            mid <<= 1;
        }
        mid <<= p;
        mid |= (1 << p);
        cout << mid - 1 << ' ' << mid << ' ';
        if (mid + 1 <= r) {
            cout << mid + 1 << '\n';
        } else {
            cout << mid - 2 << '\n';
        }
    } else {
        int mid = (1 << m - 1);
        cout << mid - 1 << ' ' << mid << ' ';
        if (mid + 1 <= r) {
            cout << mid + 1 << '\n';
        } else {
            cout << mid - 2 << '\n';
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