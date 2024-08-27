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
    string s;
    cin >> s;
    
    vector<pair<int, char>> v(26);
    for (int i = 0; i < 26; i++) {
        v[i].second = 'a' + i;
    }
    for (auto c : s) {
        v[c - 'a'].first++;
    }
    sort(v.begin(), v.end(), greater<>());
    
    int flag = 0;
    while (!flag) {
        flag = 1;
        for (auto &[x, c] : v) {
            if (x == 0) {
                continue;
            }
            flag = 0;
            cout << c;
            x--;
        }
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