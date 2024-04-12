#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = s[i] - '0'; 
    }
    for (int k = n; k; k--) {
        string t = s;
        vector<int> d(n + 2); // 异或差分数组
        for (int i = 1; i <= n; i++) {
            d[i] = a[i] ^ a[i - 1];
        }
        
        int prefix = 0;
        for (int i = 1; i <= n - k + 1; i++) {
            prefix ^= d[i];
            if (prefix == 0) {
                d[i] ^= 1, d[i + k] ^= 1;
                prefix ^= 1;
            }
        }

        int flag = 1;
        for (int i = 1; i <= n; i++) {
            d[i] ^= d[i - 1];
            if (d[i] == 0) {
                flag = 0;
                break;
            }
        }

        if (!flag) {
            continue;
        }

        cout << k << '\n';
        return;
    }
    
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