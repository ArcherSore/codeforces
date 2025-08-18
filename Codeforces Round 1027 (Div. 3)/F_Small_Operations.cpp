#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

map<int, int> factorize(int x) {
    map<int, int> f;
    for (int i = 2; i * i <= x; i++) {
        if (i > x) {
            break;
        }
        while (x % i == 0) {
            f[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        f[x]++;
    }
    return f;
}

vector<int> divisor(int x) {
    vector<int> d;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            d.push_back(i);
            if (i * i != x) {
                d.push_back(x / i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int g = gcd(x, y);
    x /= g, y /= g;
    
    auto fx = factorize(x);
    auto fy = factorize(y);

    for (auto [d, c] : fx) {
        if (d > k) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto [d, c] : fy) {
        if (d > k) {
            cout << -1 << '\n';
            return;
        }
    }

    int res = 0;

    auto work = [&](int x) -> void {
        auto div = divisor(x);
        set<int> s;
        s.insert(1);
        for (int i = 1; ; i++) {
            set<int> t;
            for (auto d : div) {
                for (auto ss : s) {
                    if (ss > k) {
                        break;
                    }
                    t.insert(ss * d);
                }
            }
            if (t.count(x)) {
                res += i;
                return;
            }
            s = t;
        }
    };

    work(x);
    work(y);

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