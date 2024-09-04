// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int MOD = 1000000007;

LL inverse(LL a, LL mod) {
    LL res = 1;
    LL b = mod - 2;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    
    LL sum = 0;
    LL sum_of_squares = 0;
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
        sum_of_squares = (sum_of_squares + (a[i] * a[i]) % MOD) % MOD;
    }
    
    LL P = ((sum * sum) % MOD - sum_of_squares + MOD) % MOD;
    
    LL Q = ((LL)n * (n - 1)) % MOD;
    
    LL Q_inv = inverse(Q, MOD);
    
    LL E = (P * Q_inv) % MOD;
    
    cout << E << "\n";
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
