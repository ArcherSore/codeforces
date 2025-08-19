#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;


vector<int> get_fac(int m) {
    vector<int> fac;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            fac.push_back(i);
            if (i * i != m) {
                fac.push_back(m / i);
            }
        }
    }
    sort(fac.begin(), fac.end());
    fac.pop_back(); // remove m
    return fac;
}

int update(int i, int k, int nk, int j) {
    int pre = 0, post = 0;
    if (i != -1) {
        pre += (k < i);
        post += (nk < i);
    }
    if (j != -1) {
        pre += (k > j);
        post += (nk > j);
    }
    return post - pre;
}

void solve() {
    /*
        m的不同因数 d < 100 <-> 潜在可能的 gcd(k, m)
        预处理出初始结果 O(dn) 5e7

        修改了一个？怎么更新？

        gcd(k, m) = 2, 最多支持 6 / 2 = 3 段
        4 5 2 2 4 1 0 -> 4 5 2 3 4 1 0
        0 1 0 0 0 1 0 -> 0 1 0 1 0 1 0
            3段               4段
        0 1 2 2 2 3 4 -> 0 1 2 3 4 5 6
            YES               NO

        gcd = 7
        0 1 4 2 5 6 0 1 6 2 4 3 -> 0 1 4 4 5 6 0 1 6 2 4 3
        - - - _ _ _ - - - _ _ -    - - - - - - _ _ _ - - _
                                -> 0 1 4 6 5 6 0 1 6 2 4 3
                                   - - - - _ _ - - - _ _ -

        所以维护上升序列的段数，每次修改之后根据两侧的大小关系更新段数；
        更新的数是 k
        1. i <= k <= j
            k' < i : +1
            k' > j : +1
        2. i > k > j
            k' >= i : -1
            k' <= j : -1
        3. i <= k > j
            1) i <= j
                i <= k' <= j : -1
            2) i > j
                i > k' > j : +1
        4. i > k <= j
            1)  i <= j
                i <= k' <= j : -1
            2) i > j
                i > k' > j : +1

        不是！为什么要这么复杂的讨论，直接算i,k,j的段数 - i,nk,j的段数就i是答案了啊...
        唐完了
    */

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> fac = get_fac(m);
    vector<vector<int>> g(fac.size(), vector<int> (n));
    vector<int> cnt(fac.size()); // the count of ascending sequence
    for (int d = 0; d < fac.size(); d++) {
        // fac[d] is potential gcd(k, m)
        int pre = -1;
        for (int i = 0; i < n; i++) {
            g[d][i] = a[i] % fac[d];

            if (g[d][i] < pre) {
                cnt[d]++;
            }
            pre = g[d][i];
        }
        cnt[d]++;
    }

    while (q--) {
        int opt, idx, x, k;
        cin >> opt;
        if (opt == 1) {
            cin >> idx >> x;
            idx--;
            for (int d = 0; d < fac.size(); d++) {
                int ng = x % fac[d];
                cnt[d] += update(idx ? g[d][idx - 1] : -1, g[d][idx], ng, (idx < n - 1) ? g[d][idx + 1] : -1);
                g[d][idx] = ng;
            }
        } else {
            cin >> k;
            // gcd(k, m) 在 fac 中的下标
            int i = lower_bound(fac.begin(), fac.end(), gcd(k, m)) - fac.begin();
            if (cnt[i] <= m / gcd(k, m)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            // cout << (cnt[i] <= m / gcd(k, m)) ? "YES\n" : "NO\n";
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