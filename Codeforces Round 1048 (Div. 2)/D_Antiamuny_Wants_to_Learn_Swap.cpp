#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> nxt(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] < a[st.top()]) {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }

    vector<int> pre(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        pre[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    vector<int> g(n, n);
    for (int j = 0; j < n; j++) {
        if (pre[j] != -1 && nxt[j] < n) {
            g[pre[j]] = min(g[pre[j]], nxt[j]);
        }
    }

    vector<int> best(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        best[i] = min(g[i], best[i + 1]);
    }

    auto check = [&](int l, int r) -> bool {
        return best[l] <= r;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (check(l, r)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
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