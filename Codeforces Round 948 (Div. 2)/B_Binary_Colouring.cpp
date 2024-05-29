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
    while (x) {
        bits.push_back(x & 1);
        x >>= 1;
    }
    bits.push_back(0);
    return bits;
}

void solve() {
    int n;
    cin >> n;
    vector<int> bits = get(n);
    int p = -1;
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] == 1 && p == -1) {
            p = i;
        }
        if (i == bits.size() - 1) {
            break;
        }
        if (bits[i + 1] == 0 && p != -1) {
            if (p != i) {
                bits[i + 1] = 1;
                bits[p] = -1;
                for (int j = p + 1; j <= i; j++) {
                    bits[j] = 0;
                }
            } 
            p = -1;
        }
    }
    n = bits.size();
    if (bits.back() == 0) {
        n -= 1;
    }
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << bits[i] << ' ';
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