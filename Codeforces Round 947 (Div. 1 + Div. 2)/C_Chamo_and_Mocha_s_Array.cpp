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

int mid(vector<int> &tmp) {
    sort(tmp.begin(), tmp.end());
    return tmp[1];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    int res = min(a[0], a[1]);
    if (n == 2) {
        cout << res << '\n';
        return;
    }
    for (int i = 0; i < n - 2; i++) {
        vector<int> tmp;
        tmp.push_back(a[i]);
        tmp.push_back(a[i + 1]);
        tmp.push_back(a[i + 2]);
        res = max(res, mid(tmp));
    }
    cout << res << '\n';
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