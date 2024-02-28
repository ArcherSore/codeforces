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

vector<int> get_fac(int x) {
    vector<int> fac;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            fac.push_back(i);
            if (i * i != x) {
                fac.push_back(x / i);
            }
        }
    }
    return fac;
}

LL check(int x, int a, int b) {
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            LL res = 1LL * pow(a, i) * pow(b, j);
            if (res > 1e6) {
                break;
            }
            if (1LL * x == res) {
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    vector<int> fac = get_fac(l);
    set<int> comb;
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            LL res = 1LL * pow(a, i) * pow(b, j);
            if (res > 1e6) {
                break;
            }
            comb.insert(res);
        }
    }

    LL res = 0;
    for (auto x : fac) {
        if (comb.find(x) != comb.end()) {
            res++;
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