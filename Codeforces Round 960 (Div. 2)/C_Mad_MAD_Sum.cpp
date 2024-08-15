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

vector<int> work(vector<int> &v, int n, LL &ans) {
    vector<int> arr(n);
    priority_queue<int> large;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
        if (cnt[v[i]] > 1) {
            large.push(v[i]);
        }
        if (!large.empty()) {
            arr[i] = large.top();
        } else {
            arr[i] = 0;
        }
    }

    for (auto x : arr) {
        ans += x;
    }
    
    return arr;
}

bool is_good(vector<int> &v) {
    int cnt = 1, n = v.size();
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            if (cnt == 1) {
                return false;
            }
            cnt = 1;
        } else {
            cnt++;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), arr;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans += v[i];
    }

    arr = work(v, n, ans);
    if (!is_good(arr)) {
        arr = work(arr, n, ans);
    }

    LL sum = 0;
    for (auto x : arr) {
        sum += x;
    }
    for (int i = n - 1; i >= 0; i--) {
        sum -= arr[i];
        ans += sum;
    }

    cout << ans << '\n';
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}