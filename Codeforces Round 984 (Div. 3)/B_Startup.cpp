#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        int b, c;
        cin >> b >> c;
        mp[b] += c;
    }
    vector<int> r;
    for (auto x : mp) {
        r.push_back(x.second);
    }
    sort(r.begin(), r.end(), greater<>());

    int res = 0;
    for (int i = 0; i < min(n, (int)r.size()); i++) {
        res += r[i];
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