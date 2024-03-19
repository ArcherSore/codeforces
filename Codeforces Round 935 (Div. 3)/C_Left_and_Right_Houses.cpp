#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    vector<int> zeros(n + 1), ones(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            zeros[i] = zeros[i - 1] + 1;
            ones[i] = ones[i - 1];
        } else {
            ones[i] = ones[i - 1] + 1;
            zeros[i] = zeros[i - 1];
        }
    }

    vector<int> res;
    for (int i = 1; i < n; i++) {
        if (ceil(1.0 * i / 2) <= zeros[i] && ceil(1.0 * (n - i) / 2) <= ones[n] - ones[i]) {
            res.push_back(i);
        }
    }

    if (ceil(1.0 * n / 2 <= ones[n])) {
        res.push_back(0);
    }
    if (ceil(1.0 * n / 2) <= zeros[n]) {
        res.push_back(n);
    }

    int ans, minn = 0x3f3f3f3f;
    for (int i = 0; i < res.size(); i++) {
        if (abs(1.0 * n / 2 - 1.0 * res[i]) < 1.0 * minn) {
            ans = res[i];
            minn = abs(n / 2 - res[i]);
        }
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}