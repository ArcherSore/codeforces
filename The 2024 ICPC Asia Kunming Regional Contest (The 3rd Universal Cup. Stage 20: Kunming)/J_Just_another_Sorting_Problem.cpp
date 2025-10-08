#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Fenwick {
    int n;
    vector<int> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, 0);
    }

    void add(int x, const int &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    int sum(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res += a[i - 1];
        }
        return res;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    int cnt = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt += (a[i] != i);
    }

    if (s == "Alice") {
        if (cnt <= 2) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        return;
    }

    int tot = 0;
    for (int i = 1; i < n; i++) {
        tot = max(tot, cnt + (a[i - 1] == (i - 1)) + (a[i] == i) - (a[i - 1] == i) - (a[i] == (i - 1)));
    }
    if (tot <= 2) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    return;
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