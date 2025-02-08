#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    LL cnt = 0, sum = 0;
    for (int i = 0; i < n; i += 2) {
        cnt += 1;
        sum += v[i];
    }
    if (sum % cnt) {
        cout << "NO\n";
        return;
    }
    LL r1 = sum / cnt;

    sum = 0, cnt = 0;
    for (int i = 1; i < n; i += 2) {
        cnt += 1;
        sum += v[i];
    }
    if (sum % cnt || sum / cnt != r1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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