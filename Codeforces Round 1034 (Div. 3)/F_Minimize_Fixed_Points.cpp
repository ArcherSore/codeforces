#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5;

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

void solve() {
    int n;
    cin >> n;
    vector<int> res(n);
    res[0] = 1;
    map<int, int> pos;
    for (int i = 2; i <= n; i++) {
        int x = i;
        while (x != minp[x]) {
            x /= minp[x];
        }
        if (x == i) {
            res[i - 1] = x;
            pos[x] = i - 1;
        } else {
            res[i - 1] = res[pos[x]];
            res[pos[x]] = i;
            pos[x] = i - 1;
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

    sieve(N);

    while (T--) {
        solve();
    }

    return 0;
}