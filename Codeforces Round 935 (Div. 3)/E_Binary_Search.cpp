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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    int p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == x) {
            p = i;
        }
    }

    int l = 1, r = n + 1, mid;
    vector<int> seq;
    while (r - l > 1) {
        mid = (l + r) / 2;
        seq.push_back(a[mid]);
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (n == 1 || seq.back() == x) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
        cout << p << " " << l << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}