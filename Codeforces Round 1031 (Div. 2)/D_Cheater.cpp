#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] < k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    Fenwick<int> fw(2 * n + 1);
    for (auto x : a) {
        fw.add(x, 1);
    }

    int mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, b[i]);
        int cnt = fw.sum(mn + 1);
        if (cnt == 0 || cnt == 1 && mx >= mn) {
            cout << n - i << '\n';
            return;
        }
        mx = max(mx, a[n - i - 1]);
        fw.add(a[n - i - 1], -1);
    }
    cout << 0 << '\n';
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