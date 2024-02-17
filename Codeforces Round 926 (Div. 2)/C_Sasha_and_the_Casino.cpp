#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;
    
    LL sum = 0;
    for (int i = 0; i <= x; i++) {
        LL y = sum / (k - 1) + 1;
        sum += y;
        if (sum > a) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}