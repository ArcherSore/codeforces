#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    vector<PII> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    v.push_back({m, m});
    int st = 0;
    for (int i = 0; i < n + 1; i++) {
        if (v[i].first - st >= s) {
            cout << "YES\n";
            return;
        }
        st = v[i].second;
    }
    cout << "NO\n";
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