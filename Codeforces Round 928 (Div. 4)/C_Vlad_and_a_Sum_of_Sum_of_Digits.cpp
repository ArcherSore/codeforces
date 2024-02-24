#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

const int MAXN = 2e5 + 10;

int dig[MAXN], res[MAXN];

void init() {
    for (int i = 1; i <= 2e5; i++) {
        if (i % 10) {
            dig[i] = dig[i - 1] + 1;
        } else {
            dig[i] = dig[i / 10];
        }
        res[i] = res[i - 1] + dig[i];
    }
}

void solve() {
    int n;
    cin >> n;
    cout << res[n] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}