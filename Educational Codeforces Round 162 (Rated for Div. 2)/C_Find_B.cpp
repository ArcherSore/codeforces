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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    vector<LL> sum(n + 1);
    vector<LL> num(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i] - 1;
        num[i] = num[i - 1] + (a[i] == 1 ? 1 : 0); 
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "NO\n";
            continue;
        }
        LL cnt = num[r] - num[l - 1]; // 1的数量
        LL pre = sum[r] - sum[l - 1]; // 前缀和
        // cout << cnt << " " << pre << '\n';
        if (cnt <= pre) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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