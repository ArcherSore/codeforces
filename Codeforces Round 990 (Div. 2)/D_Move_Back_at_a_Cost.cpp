#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    queue<int> q;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        q.push(x);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    while (!q.empty()) {
        int mn = (*cnt.begin()).first;
        if (!pq.empty() && mn > pq.top()) {
            while (!q.empty()) {
                pq.push(q.front() + 1);
                q.pop();
            }
            break;
        }
        cout << mn << ' ';
        while (q.front() != mn) {
            int t = q.front();
            q.pop();
            cnt[t]--;
            if (cnt[t] == 0) {
                cnt.erase(t);
            }
            pq.push(t + 1);
        }
        q.pop();
        cnt[mn]--;
        if (cnt[mn] == 0) {
            cnt.erase(mn);
        }
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
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