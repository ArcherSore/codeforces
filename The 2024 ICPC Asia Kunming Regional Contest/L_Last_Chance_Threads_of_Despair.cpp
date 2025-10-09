#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt1 = count(a.begin(), a.end(), 1);
    int exp = 0, d = n;
    if (a[0] == 1) {
        exp = 1;
        d = n - cnt1 + 1;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            break;
        }
        pq.push({a[i] - 1, 0});
    }
    while (cnt1 > 1) {
        pq.push({1, 0});
        cnt1--;
    }
    for (int i = 0; i < m; i++) {
        pq.push({b[i], 1});
    }

    queue<int> q;
    while (!pq.empty()) {
        while (!q.empty() && q.front() <= exp) {
            exp++;
            q.pop();
        }
        auto [h, id] = pq.top();
        if (id == 0) {
            if (exp >= h) {
                exp++;
            } else {
                q.push(h);
            }
            pq.pop();
        } else {
            if (exp >= h) {
                exp++;
            } else if (exp + d >= h) {
                d -= h - exp;
                exp++;
            } else {
                break;
            }
            pq.pop();
        }
    }

    while (!pq.empty()) {
        auto [h, id] = pq.top();
        if (id == 1) {
            cout << "No\n";
            return;
        }
        pq.pop();
    }
    cout << "Yes\n";
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