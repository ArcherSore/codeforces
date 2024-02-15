#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <numeric>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

LL C2(LL n) {
    return n * (n - 1) / 2;
}

LL C3(LL n) {
    return n * (n - 1) * (n - 2) / 6;
}

void solve() {
    LL n;
    cin >> n;
    vector<LL> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());

    if (n < 3) {
        cout << 0 << '\n';
        return;
    }

    vector<LL> cnt;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (cnt.empty() || last != sticks[i]) {
            cnt.push_back(1);
            last = sticks[i];
        } else {
            cnt.back()++;
        }
    }
    int k = cnt.size();
    vector<LL> sum(k);
    sum[0] = cnt[0];
    for (int i = 1; i < k; i++) {
        sum[i] = sum[i - 1] + cnt[i];
    }

    LL count = 0;
    for (int i = 0; i < k; i++) {
        LL x = cnt[i];
        if (x >= 3) count += C3(x);
        if (x >= 2 && i) count += C2(x) * sum[i - 1];
    }
    cout << count << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}