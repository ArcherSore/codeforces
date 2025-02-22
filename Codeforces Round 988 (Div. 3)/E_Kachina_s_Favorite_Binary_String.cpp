#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << ' ' << i << endl;
        cin >> cnt[i];
    }
    
    string s;
    int last = 0;
    int tcnt = 0, cnt0 = 0;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] && cnt[i] != cnt[i - 1]) {
            int zeros = cnt[i] - (tcnt + cnt0);
            int ones = (i - last - 1) - zeros;
            s.append(ones, '1');
            s.append(zeros, '0');
            s.append(1, '1');

            tcnt += cnt0 + zeros;
            cnt0 += zeros;
            last = i;
        }
    }
    if (last == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    s.append(n - last, '0');
    cout << "! " << s << endl;
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