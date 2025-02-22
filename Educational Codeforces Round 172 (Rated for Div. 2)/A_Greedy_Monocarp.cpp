#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int sum = 0;
    for (auto &x : v) {
        cin >> x;
        sum += x;
    }
    if (sum <= k) {
        cout << k - sum << '\n';
        return;
    }
    priority_queue<int> pq;
    for (auto x : v) {
        pq.push(x);
    }
    int tot = 0;
    while (tot + pq.top() <= k) {
        tot += pq.top();
        pq.pop();
    }
    cout << k - tot << '\n';
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