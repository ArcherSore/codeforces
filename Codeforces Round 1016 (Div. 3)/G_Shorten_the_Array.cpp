#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int MAXN = 2e5 + 1;
int trie[MAXN * 31][2];
int cnt[MAXN * 31];
int tot = 1;

void insert(int x, int t) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (trie[p][c] == 0) {
            trie[p][c] = ++tot;
        }
        p = trie[p][c];
        cnt[p] += t;
    }
}

int query(int x) {
    int p = 1, res = 0;
    for (int i = 30; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (cnt[trie[p][c ^ 1]] != 0) {
            res |= (1 << i);
            p = trie[p][c ^ 1];
        } else {
            p = trie[p][c];
        }
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }

    int res = n + 1;
    for (int i = 0, j = 0; i < n; i++) {
        insert(v[i], 1);
        while (j <= i && query(v[i]) >= k) {
            res = min(res, i - j + 1);
            insert(v[j], -1);
            j++;
        }
    }
    cout << (res == n + 1 ? -1 : res) << '\n';

    for (int i = 1; i <= tot; i++) {
        trie[i][0] = trie[i][1] = 0;
        cnt[i] = 0;
    }
    tot = 1;
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