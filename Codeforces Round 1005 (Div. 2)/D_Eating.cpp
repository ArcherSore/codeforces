#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int get_width(int x) {
    int len = 0;
    while (x) {
        x >>= 1;
        len++;
    }
    return len;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = n; i; i--) {
        cin >> v[i];
    }
    vector<int> width(n + 1);
    for (int i = 1; i <= n; i++) {
        width[i] = get_width(v[i]);
    }
    /*
        预处理[l, n]中第一个大于等于wd的位置！
        方法：从后往前遍历！
        如果该位置大于等于wd，说明当前位置就是第一个大于等于wd的位置
        否则，继承上一个位置的答案
    */
    vector<vector<int>> nxt(32, vector<int> (n + 1));
    for (int i = 0; i < 32; i++) {
        nxt[i][n] = width[n] >= i ? n : -1;
        for (int j = n - 1; j; j--) {
            nxt[i][j] = width[j] >= i ? j : nxt[i][j + 1];
        }
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] ^ v[i];
    }

    while (q--) {
        int x, wd;
        cin >> x;
        int cur = 0;
        while (cur < n) {
            wd = get_width(x);
            int pos = nxt[wd][cur + 1];
            if (pos == -1) {
                cur = n;
                break;
            }
            x ^= (pre[pos - 1] ^ pre[cur]);
            if (x < v[pos]) {
                cur = pos - 1;
                break;
            }
            cur = pos;
            x ^= v[pos];
        }
        cout << cur << ' ';
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