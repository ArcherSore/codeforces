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
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<LL>> a(n + 1, vector<LL> (n + 1));
    multiset<LL> s;
    for (int i = 0; i < n * n; i++) {
        LL x;
        cin >> x;
        s.insert(x);
    }
    a[1][1] = *s.begin();
    // cout << a[1][1] << '\n';
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            a[i][1] = a[i - 1][1] + c;
        }
        for (int j = 2; j <= n; j++) {
            a[i][j] = a[i][j - 1] + d;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            auto p = s.find(a[i][j]);
            if (p == s.end()) {
                cout << "NO\n";
                return;
            } else {
                s.erase(p);
            }
        }
    }
    cout << "YES\n";
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