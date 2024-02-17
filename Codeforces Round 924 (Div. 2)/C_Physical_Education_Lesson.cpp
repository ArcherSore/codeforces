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

void get_factor(set<int> &factor, int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factor.insert(i);
            if (i * i != x) {
                factor.insert(x / i);
            }
        }
    }
    return;
}

int cal(set<int> &factor, int x) {
    int res = 0;
    for (int fac : factor) {
        if (fac % 2 == 0 && fac / 2 + 1 >= x) {
            res++;
        } 
    }
    return res;
}

void solve() {
    int n, x, res = 0;
    cin >> n >> x;
    set<int> factor;
    get_factor(factor, n - x);
    get_factor(factor, n + x - 2);
    
    res += cal(factor, x);

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