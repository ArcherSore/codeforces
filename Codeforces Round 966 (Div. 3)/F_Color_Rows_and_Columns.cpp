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

const int INF = 1e9;
const int N = 210;

vector<vector<int>> get_score(int n, int k, vector<PII> &v) {
    vector<vector<int>> score(n, vector<int> (N));
    for (int i = 0; i < n; i++) {
        auto [a, b] = v[i];
        score[i][a + b] = score[i][a + b - 1] = a * b;

        int scor = 0, cost = 0;
        while (a > 1 || b > 1) {
            if (a > b) {
                swap(a, b);
            }
            scor += 1;
            cost += a;
            b -= 1;
            score[i][scor] = cost;
        }
    }

    return score;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<PII> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<vector<int>> score;
    score = get_score(n, k, v);

    vector<int> f(2 * k + 1, INF);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 2 * k; j >= 0; j--) {
            auto [a, b] = v[i];
            for (int t = 1; t <= a + b; t++) {
                f[j] = min(f[j], f[max(0, j - t)] + score[i][t]);
            }
        }
    }

    int ans = INF;
    for (int i = k; i <= 2 * k; i++) {
        ans = min(ans, f[i]);
    }

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
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