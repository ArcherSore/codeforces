#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<LL> prime;

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void init() {
    for (int i = 2; i <= 1e5; i++) {
        if (isprime(i)) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 2 << ' ' << 1 << '\n';
        return;
    }
    int p = -1, mx = 0;
    for (auto pri : prime) {
        if (pri <= n) {
            if (min(pri - 1, n - pri) > mx) {
                p = pri;
                mx = min(pri - 1, n - pri);
            }
        } else {
            break;
        }
    }
    int l = p - 1, r = p + 1;
    cout << p << ' ';
    while (l > 0 && r <= n) {
        cout << l << ' ' << r << ' ';
        l--, r++;
    }
    while (l > 0) {
        cout << l << ' ';
        l--;
    }
    while (r <= n) {
        cout << r << ' ';
        r++;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    init();

    while (T--) {
        solve();
    }

    return 0;
}