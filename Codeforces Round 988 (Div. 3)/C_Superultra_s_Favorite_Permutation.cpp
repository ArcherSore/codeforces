#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << -1 << '\n';
        return;
    }
    deque<int> dq;
    dq.push_back(2);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(1);
    dq.push_back(3);
    for (int i = 6; i <= n; i++) {
        if (i & 1) {
            dq.push_back(i);
        } else {
            dq.push_front(i);
        }
    }

    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    cout << '\n';
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