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

vector<int> to_bin(LL n) {
    vector<int> bin;
    while (n) {
        bin.push_back(n & 1);
        n >>= 1;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

void solve() {
    LL n;
    cin >> n;

    vector<int> bin = to_bin(n);

    int ones = 0;
    for (auto x : bin) {
        if (x) {
            ones++;
        }
    }

    if (ones == 1) {
        cout << ones << '\n' << n  << '\n';
        return;
    }

    cout << ones + 1 << '\n';
    for (int i = 0; i <= ones; i++) {
        int cnt = 0;
        LL ans = 0;
        for (auto x : bin) {
            ans <<= 1;
            if (x == 1) {
                if (cnt != i) {
                    ans |= 1;
                }
                cnt++;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
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