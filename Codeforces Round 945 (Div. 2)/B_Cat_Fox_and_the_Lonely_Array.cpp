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

const int N = 1e5 + 10;

int n;
int a[N];

void add(int x, vector<int> &bit) {
    int p = 0;
    while (x) {
        if (x & 1) {
            bit[p] += 1;
        }
        p++;
        x >>= 1;
    }
}

void del(int x, vector<int> &bit) {
    int p = 0;
    while (x) {
        if (x & 1) {
            bit[p] -= 1;
        }
        p++;
        x >>= 1;
    }
}

int cal(vector<int> &bit) {
    int res = 0;
    for (int i = 0; i < 31; i++) {
        if (bit[i]) {
            res += (1 << i);
        }
    }
    return res;
}

bool check(int k) {
    vector<int> bit(31);
    for (int i = 1; i <= k; i++) {
        add(a[i], bit);
    }
    int std = cal(bit);
    for (int i = 1; i < n - k + 1; i++) {
        del(a[i], bit);
        add(a[i + k], bit);
        if (std != cal(bit)) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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