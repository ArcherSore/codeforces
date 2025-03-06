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
    
    LL sum = 0, res = 0;
    set<LL> s;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (s.find(sum) != s.end()) {
            res++;
            sum = 0;
            s.clear();
            s.insert(0);
        } else {
            s.insert(sum);
        }
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