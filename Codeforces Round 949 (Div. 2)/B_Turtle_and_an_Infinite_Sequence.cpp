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

vector<int> get(int x) {
    vector<int> bits;
    for (int i = 0; i < 31; i++) {
        bits.push_back(x & 1);
        x >>= 1;
    }
    return bits;
}

int cal(vector<int> &bits) {
    int ans = 0;
    for (int i = 0; i < bits.size(); i++) {
        ans |= (bits[i] << i);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> bits = get(n);

    int pre = 0;
    vector<int> ans;
    for (int i = 0; i < 31; i++) {
        if (bits[i] == 0 && ((1 << i) - pre <= m || pre + 1 <= min(n, m))) {
            ans.push_back(1);
        } else {
            ans.push_back(bits[i]);
        }
        if (bits[i]) {
            pre |= (1 << i);
        }
    }

    while (!ans.empty() && ans.back() == 0) {
        ans.pop_back();
    }

    cout << cal(ans) << '\n';
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