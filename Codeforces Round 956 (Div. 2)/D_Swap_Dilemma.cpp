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

const int MAXN = 1e5 + 10;

int n;
vector<LL> tr(MAXN);

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

LL ask(int x) {
    LL sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += tr[i];
    }
    return sum;
}

int parity(vector<int> &a) {
    tr.assign(MAXN, 0);
    LL tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += ask(n) - ask(a[i]);
        add(a[i], 1);
    }
    return tot % 2;
}

void solve() {
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> t1 = a, t2 = b;
    sort(t1.begin() + 1, t1.end());
    sort(t2.begin() + 1, t2.end());
    if (t1 != t2) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(t1.begin() + 1, t1.end(), a[i]) - t1.begin();
    }
    for (int i = 1; i <= n; i++) {
        b[i] = lower_bound(t2.begin() + 1, t2.end(), b[i]) - t2.begin();
    }

    // cout << parity(a) << " " << parity(b) << '\n';

    if (parity(a) == parity(b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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