#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct State {
    int w, h;
    int id;
};

void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<State> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > w && b > h) {
            v.push_back({a, b, i + 1});
        }
    }
    sort(v.begin(), v.end(), [](const State &a, const State &b) {
        if (a.w != b.w) {
            return a.w < b.w;
        }
        return a.h < b.h;
    });

    if (v.empty()) {
        cout << 0 << '\n';
        return;
    }

    n = v.size();
    vector<int> dp(n, 1), from(n, -1);
    int bs = 0, id = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].w < v[i].w && v[j].h < v[i].h && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                from[i] = j;
            }
        }
        if (dp[i] > bs) {
            bs = dp[i];
            id = i;
        }
    }

    cout << bs << '\n';
    vector<int> chain;
    for (int i = id; i != -1; i = from[i]) {
        chain.push_back(v[i].id);
    }
    reverse(chain.begin(), chain.end());
    for (auto x : chain) {
        cout << x << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}