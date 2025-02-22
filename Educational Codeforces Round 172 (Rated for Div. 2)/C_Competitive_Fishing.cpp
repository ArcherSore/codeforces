#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> more(n);
    more[n - 1] = s[n - 1] == '0' ? -1 : 1;
    for (int i = n - 2; i > 0; i--) {
        more[i] = more[i + 1] + (s[i] == '0' ? -1 : 1);
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (more[i] > 0) {
            pq.push(more[i]);
        }
    }
    int sc = 0, cnt = 1;
    while (!pq.empty() && sc < k) {
        cnt++;
        sc += pq.top();
        pq.pop();
    }
    if (sc < k) {
        cout << -1 << '\n';
    } else {
        cout << cnt << '\n';
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