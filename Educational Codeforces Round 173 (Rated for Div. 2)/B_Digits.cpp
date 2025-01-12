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
    LL n, d;
    cin >> n >> d;

    vector<int> ans;

    ans.push_back(1);
    if (n >= 3 || (n == 2 && d % 3 == 0)){
        ans.push_back(3);
    }
    if (d == 5){
        ans.push_back(5);
    }
    if (n >= 3 || (n == 2 && d == 7)){
        ans.push_back(7);
    }
    if (n >= 6){
        ans.push_back(9);
    } else {
        if (n == 5 && d % 3 == 0) {
            ans.push_back(9);
        }
        if (n == 4 && d % 3 == 0) {
            ans.push_back(9);
        }
        if (n == 3 && d % 3 == 0) {
            ans.push_back(9);
        }
        if (n == 2 && d == 9) {
            ans.push_back(9);
        }
    }

    for(int x : ans){
        cout << x << ' ';
    }
    cout << "\n";
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