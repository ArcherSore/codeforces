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
    int n, k;
    cin >> n >> k;
    set<int> a, b;
    vector<int> num1(n + 1), num2(n + 1);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.insert(x);
        num1[x]++;
    }
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b.insert(x);
        num2[x]++;
    }

    vector<int> e1, e2;
    for (int i = 1; i <= n; i++) {
        if (num1[i] == 2) {
            e1.emplace_back(i);
        }
        if (num2[i] == 2) {
            e2.emplace_back(i);
        }
    }

    if (e1.empty() || e1.size() < k) {
        int rest = 2 * (k - e1.size());
        int it = 0;
        if (!e1.empty()) {
            for (auto x : e1) {
                cout << x << " " << x << " ";
                a.erase(x);
            }
        }
        it = 0;
        for (auto x : a) {
            if (it == rest) {
                break;
            }
            cout << x << " ";
            it++;
        }
        cout << '\n';

        if (!e2.empty()) {
            for (auto x : e2) {
                cout << x << " " << x << " ";
                b.erase(x);
            }
        }
        it = 0;
        for (auto x : b) {
            if (it == rest) {
                break;
            }
            cout << x << " ";
            it++;
        }
        cout << '\n';
    } else {
        for (int i = 0; i < k; i++) {
            cout << e1[i] << " " << e1[i] << " ";
        }
        cout << '\n';
        for (int i = 0; i < k; i++) {
            cout << e2[i] << " " << e2[i] << " ";
        }
        cout << '\n';
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