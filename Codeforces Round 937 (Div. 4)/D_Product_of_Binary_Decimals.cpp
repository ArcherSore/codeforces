// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int n = 31;
vector<int> fac = {1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1100, 1011, 1101, 1110, 1111, 10000, 10001, 
            10010, 10100, 11000, 10011, 10101, 11001, 10110, 11010, 11100, 10111, 11011, 11101, 11110, 11111, 100000};
set<LL> res;

// n = 31;
void init2() {
    for (int i = 1; i < 31; i++) {
        LL mul = fac[i] * fac[i];
        while (mul < 100000) {
            fac.push_back(mul);
            mul *= fac[i];
        }
    }
    sort(fac.begin(), fac.end());
    unique(fac.begin(), fac.end());
    // for (auto f : fac) {
    //     cout << f << '\n';
    // }
    n = fac.size();
}

void init(int lvl, LL mul) {
    if (mul > 100000 || lvl == n) {
        return;
    }
    res.insert(mul);
    init(lvl + 1, mul);
    init(lvl + 1, mul * fac[lvl]);
}

void solve() {
    int x;
    cin >> x;
    if (res.find(x) != res.end()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    init2();
    init(0, 1);

    while (T--) {   
        solve();
    }

    return 0;
}