#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 5e5;
const int INF = 1e9;

vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

vector<pair<int,int>> fac;
void gen_divs(int idx, int cur, vector<int> &divs) {
    if (idx == fac.size()) {
        divs.push_back(cur);
        return;
    }
    int p = fac[idx].first, e = fac[idx].second;
    int v = 1;
    for (int k = 0; k <= e; k++) {
        gen_divs(idx + 1, cur * v, divs);
        v *= p;
    }
}

vector<int> dp, cost;

void init() {
    dp.assign(N + 1, INF);
    cost.assign(N + 1, INF);
    dp[1] = 1;
    cost[1] = 0;

    for (int i = 3; i <= N; i += 2) {
        fac.clear();
        int t = i;
        while (t > 1) {
            int p = minp[t], cnt = 0;
            while (t % p == 0) {
                t /= p;
                cnt++;
            }
            fac.emplace_back(p, cnt);
        }
        vector<int> divs;
        divs.reserve(1 << fac.size());
        gen_divs(0, 1, divs);

        int best_c = INF;
        for (int d : divs) {
            if (d < 3) {
                continue;
            }
            int rem = i / d;
            best_c = min(best_c, dp[d - 2] + cost[rem]);
        }
        cost[i] = best_c;
        dp[i] = 1 + cost[i];
    }
}

void solve() {
    int m;
    cin >> m;
    if (m % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    cout << dp[m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(N);
    init();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}