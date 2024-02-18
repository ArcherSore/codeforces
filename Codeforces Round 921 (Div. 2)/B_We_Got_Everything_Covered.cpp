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

vector<int> get_factor(int x) {
    vector<int> factor;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i != x) {
                factor.push_back(x / i);
            }
            factor.push_back(i);
        }
    }
    return factor;
}

void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> factor = get_factor(x);
    sort(factor.begin(), factor.end());

    int res;
    for (int fac : factor) {
        if (x / fac < n) {
            break;
        } else {
            res = fac;
        }
    }
    cout << res << '\n';
    return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}