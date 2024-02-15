#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

LL dig[10] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};

void solve() {
    LL n;
    cin >> n;
    LL ans = 1;
    while (n) {
        ans *= dig[n % 10];
        n /= 10;
    }
    cout << ans << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}