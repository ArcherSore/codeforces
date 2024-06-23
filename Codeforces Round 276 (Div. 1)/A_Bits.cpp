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

vector<int> get_bits(LL x) {
    vector<int> bits;
    for (int i = 0; i < 61; i++) {
        bits.push_back(x & 1);
        x >>= 1;
    }
    return bits;
}

bool check(vector<int> &bits, LL r) {
    LL tmp = 0;
    for (int i = bits.size() - 1; i >= 0; i--) {
        tmp = (tmp << 1) | bits[i];
    }
    return tmp <= r;
}

void solve() {
    LL l, r;
    cin >> l >> r;
    vector<int> bits = get_bits(l);
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] == 0) {
            bits[i] = 1;
            if (!check(bits, r)) {
                bits[i] = 0;
                break;
            }
        }
    }

    LL res = 0;
    for (int i = bits.size() - 1; i >= 0; i--) {
        res = (res << 1) | bits[i];
    }
    cout << res << '\n';
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