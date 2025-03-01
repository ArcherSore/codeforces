#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool perfect(LL x) {
    LL k = sqrtl(1.0 * x);
    return k * k == x;
}

void solve() {
    int n;
    cin >> n;
    LL total = 1LL * (n + 1) * n / 2;
    if (perfect(total)) {
        cout << -1 << '\n';
        return;
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = n - i;
    }
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        sum += res[i];
        if (i < n - 1 && perfect(sum)) {
            LL tmp = sum - res[i];
            for (int j = i + 1; j < n; j++) {
                if (!perfect(tmp + res[j])) {
                    swap(res[i], res[j]);
                    sum = tmp + res[i];
                    break;
                }
            }
        }
    }

    for (auto x : res) {
        cout << x << ' ';
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