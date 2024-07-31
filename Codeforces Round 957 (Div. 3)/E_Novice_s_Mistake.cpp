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

LL cal(int n, int i, int add) {
    LL x = n, dig = add;
    while (dig <= i) {
        x = 1LL * x * (LL)pow(10, add) + 1LL * n;
        dig += add;
    }
    while (dig > i) {
        x /= 10;
        dig -= 1;
    }
    return x;
}

void solve() {
    int n, add;
    cin >> n;
    if (n == 1) {
        cout << 9999 << '\n';
        for (int i = 2; i <= 10000; i++) {
            cout << i << " " << i - 1 << '\n';
        }
        return;
    }
    if (n < 10) {
        add = 1;
    } else if (n < 100) {
        add = 2;
    } else {
        add = 3;
    }
    vector<PII> res;
    for (int i = 1; i <= 8; i++) {
        LL dig = cal(n, i, add);
        if ((dig - i) % (n - add) != 0) {
            continue;
        }
        LL a = (dig - i) / (n - add), b = add * a - i;
        if (a <= 10000LL && b <= min(10000LL, a * n) && a > 0 && b > 0) {
            res.push_back({a, b});
        }
    }

    cout << res.size() << '\n';
    for (auto [a, b] : res) {
        cout << a << " " << b << '\n';
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