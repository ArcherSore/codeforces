#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 30;

int popbit(int x) {
    int pos = -1;
    while (x > 0) {
        x >>= 1;
        pos++;
    }
    return pos;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] ^ v[i];
    }
    vector<vector<LL>> pre(N, vector<LL> (n + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i][j - 1] + ((s[j] >> i) & 1);
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        int k = popbit(v[i]);
        if (k == -1) {
            continue;
        }
        res += pre[k][i - 1] * (pre[k][n] - pre[k][i - 1]);
        res += (i - pre[k][i - 1]) * (n - i + 1 - (pre[k][n] - pre[k][i - 1]));
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