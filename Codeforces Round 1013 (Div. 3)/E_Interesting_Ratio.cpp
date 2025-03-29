#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int N = 1e7;
vector<bool> is_prime(N + 1, true);
vector<int> prime;

void init() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }
}

void solve() {
    LL n;
    cin >> n;

    LL res = 0;
    for (LL i = 1; i <= n; i++) {
        LL le = 0, ri = prime.size() - 1, mid;
        LL p = -1;
        while (le <= ri) {
            mid = (le + ri) / 2;
            if (i * prime[mid] <= n) {
                p = mid;
                le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }
        res += p + 1;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}