#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<int> fact(int x) {
    vector<int> f;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            f.push_back(i);
        }
    }
    if (x != 1) {
        f.push_back(x);
    }
    if (f.size() > 2) {
        return {};
    }
    return f;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    int tot_one = 0;
    map<int, int> ones;
    vector<PII> twos;
    for (int i = 0; i < n; i++) {
        vector<int> f = fact(v[i]);
        if (f.size() == 1) {
            ones[f[0]]++;
            tot_one++;
        } else if (f.size() == 2) {
            twos.emplace_back(f[0], f[1]);
        }
    }


    LL res = 0;
    // part1 {p1}+{p2} (p1 != p2)
    for (auto [x, c] : ones) {
        tot_one -= c;
        res += 1LL * c * tot_one;
    }
    map<int, int> cnt;
    for (auto [i, j] : twos) {
        cnt[i]++;
        if (i != j) {
            cnt[j]++;
        }
    }
    // cout << res << ' ';
    // part2 {p1}+{p1,p2}
    for (auto [x, c] : ones) {
        res += 1LL * cnt[x] * c;
    }
    // cout << res << ' ';

    // part3 本身能分解成 p1 * p2
    res += twos.size();

    // part4 {p1,p2}+{p1,p2}
    map<PII, int> cnt_pairs;
    for (auto x : twos) {
        cnt_pairs[x]++;
    }
    for (auto [x, c] : cnt_pairs) {
        res += 1LL * c * (c - 1) / 2;
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