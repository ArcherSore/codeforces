#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 5000;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    int g = 0;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        g = gcd(g, x);
    }
    int cnt = count(a.begin(), a.end(), g);
    if (cnt) {
        cout << n - cnt << '\n';
        return;
    }

    vector<int> res(N + 1, INF);
    for (int i = 0; i < n; i++) {
        vector<int> tmp = res;
        tmp[a[i]] = min(tmp[a[i]], 1);
        for (int d = 1; d <= N; d++) {
            if (res[d] != INF) {
                int td = gcd(d, a[i]);
                tmp[td] = min(tmp[td], res[d] + 1);
            }
        }
        res = tmp;
    }

    cout << res[g] + n - 2 << '\n';
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