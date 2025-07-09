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
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }

    int rdc = -1;
    vector<PII> res;
    for (int i = 0; i < n; i++) {
        Fenwick<int> fw(n);
        fw.add(v[i], 1);
        for (int j = i + 1; j < n; j++) {
            fw.add(v[j], 1);
            if (v[i] < v[j]) {
                continue;
            }
            int cnt = 1 + 2 * fw.rangeSum(v[j] + 1, v[i]);
            if (cnt > rdc) {
                rdc = cnt;
                res.clear();
                res.emplace_back(i, j);
            } else if (cnt == rdc) {
                res.emplace_back(i, j);
            }
        }
    }

    int tot = 0;
    Fenwick<int> fw(n);
    for (int i = n - 1; i >= 0; i--) {
        fw.add(v[i], 1);
        tot += fw.rangeSum(0, v[i]);
    }
    cout << tot - rdc << ' ' << res.size() << '\n';
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