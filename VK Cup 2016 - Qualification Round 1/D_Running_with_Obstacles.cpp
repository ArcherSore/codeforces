#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    vector<pair<string, int>> res;
    int lst = 0, i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && a[j + 1] - a[j] <= s + 1) {
            j++;
        }

        int run_dist = (a[i] - 1) - lst;
        if (run_dist < s) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        res.push_back({"RUN", run_dist});

        int jmp_dist = a[j] - a[i] + 2;
        if (jmp_dist > d) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        res.push_back({"JUMP", jmp_dist});

        lst = a[j] + 1;
        i = j + 1;
    }

    int run_dist = m - lst;
    if (run_dist > 0) {
        res.push_back({"RUN", run_dist});
    }

    for (auto [o, d] : res) {
        cout << o << ' ' << d << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}