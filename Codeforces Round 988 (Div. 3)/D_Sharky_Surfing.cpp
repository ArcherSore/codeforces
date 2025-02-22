#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<PII> hurdle(n);
    for (int i = 0; i < n; i++) {
        cin >> hurdle[i].first >> hurdle[i].second;
    }
    vector<int> x(m), v(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> v[i];
    }

    int res = 0, p = 0, k = 1;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        while (p < m && x[p] < hurdle[i].first) {
            pq.push(v[p]);
            p++;
        }
        int len = hurdle[i].second - hurdle[i].first + 2;
        while (!pq.empty() && k < len) {
            res++;
            k += pq.top();
            pq.pop();
        }
        if (k < len) {
            cout << -1 << '\n';
            return;
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