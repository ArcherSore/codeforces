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
    priority_queue<int, vector<int>, greater<int>> st;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    int opt = 5;
    while (opt--) {
        int t = st.top();
        st.pop();
        st.push(t + 1);
    }

    vector<int> arr;
    while (!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }

    LL res = 1;
    for (auto x : arr) {
        res *= 1LL * x;
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