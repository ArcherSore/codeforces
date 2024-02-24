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

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

LL P[MAXN];

void init() {
    P[0] = P[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        P[i] = (P[i - 1] * i) % MOD;
    }
    return;
}

void solve() {
    string s;
    cin >> s;
    int pre = s[0];
    vector<int> cnt;
    cnt.push_back(1);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != pre) {
            pre = s[i];
            cnt.push_back(1);
        } else {
            cnt.back()++;
        }
    }

    int opt = s.size() - cnt.size();
    LL num = 1;
    for (auto x : cnt) {
        num = (num * x) % MOD;
    }
    cout << opt << " " << num * P[opt] % MOD << '\n';


    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}