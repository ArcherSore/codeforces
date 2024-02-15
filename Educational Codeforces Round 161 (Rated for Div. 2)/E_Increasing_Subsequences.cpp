#include <iostream>
#include <string>
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

LL pow(LL a, LL b) {
    if (b == 0) return 1;
    LL res = pow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

void solve() {
    LL n, k = 0;
    cin >> n;
    LL straight = pow(2, (LL)log2(n));
    LL rest = n - straight;
    LL cnt = log2(n);

    LL t = rest;
    while (t) {
        if (t & 1) k++;
        t >>= 1;
    }
    // cout << cnt + k << endl;
    printf("%lld\n", cnt + k);

    k = 0;
    if (rest == 0) {
        for (LL i = 1; i <= cnt; i++) {
            // cout << i << " ";
            printf("%lld ", i);
        }
        printf("\n");
        return;
    }

    while (rest) {
        if (rest & 1) {
            // cout << cnt - k << " ";
            printf("%lld ", cnt - k);
        }
        rest >>= 1;
        k++;
    }
    for (LL i = 1; i <= cnt; i++) {
        // cout << i << " " ;
        printf("%lld ", i);
    }
    // cout << '\n';
    printf("\n");
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