#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

struct Segment {
    int l, r;
};

bool cmp(Segment &a, Segment &b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Segment> seg(m);
    vector<int> suffix(n + 1); // 差分数组
    vector<int> s(n); // 记录每个位置有几条线段
    for (int i = 0; i < m; i++) {
        cin >> seg[i].l >> seg[i].r;
        seg[i].l--, seg[i].r--;
    }
    sort(seg.begin(), seg.end(), cmp);
    for (int i = 0; i < m; i++) {
        suffix[seg[i].l]++, suffix[seg[i].r + 1]--;
    }
    // 求每个位置有几条线段
    for (int i = 0; i < n; i++) {
        if (!i) {
            s[i] = suffix[i];
        } else {
            s[i] = s[i - 1] + suffix[i];
        }
    }
    // 求这个位置最前面的线段端点
    vector<int> pre(n);
    int p = 0; // 模拟队列的指针
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            continue;
        }
        while (seg[p].r < i) {
            p++;
        }
        pre[i] = seg[p].l;
    }
    // dp
    vector<int> dp(n);
    dp[0] = s[0];
    for (int i = 1; i < n; i++) {
        if (pre[i] == 0) {
            dp[i] = max(dp[i - 1], s[i]);
        } else {
            dp[i] = max(dp[i - 1], dp[pre[i] - 1] + s[i]);
        }
    }
    cout << dp[n - 1] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}