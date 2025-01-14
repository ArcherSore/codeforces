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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int cnt = 0, pos, need;
    vector<int> pro(n);
    for (int i = 0; i < n; i++) {
        if (b[i] - a[i] > 0) {
            cnt++;
            pos = i;
            need = b[i] - a[i];
        } else {
            pro[i] = a[i] - b[i];
        }
    }
    if (cnt > 1) {
        cout << "NO\n";
    } else if (cnt == 0) {
        cout << "YES\n";
    } else {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (i == pos) {
                continue;
            }
            if (pro[i] < need) {
                flag = false;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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