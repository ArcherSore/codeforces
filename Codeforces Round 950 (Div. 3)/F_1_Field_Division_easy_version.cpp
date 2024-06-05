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
using PII = pair<LL, LL>;

struct Pos {
    int id;
    LL x, y;
    bool operator<(const Pos &other) const {
        if (x != other.x) {
            return x < other.x;
        } else {
            return y < other.y;
        }
    }
};

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<Pos> pos(k);
    vector<LL> pre(k), add(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        pos[i] = {i, x, y};
    }
    sort(pos.begin(), pos.end());
    
    stack<Pos> st;
    for (auto [id, x, y] : pos) {
        if (st.empty()) {
            st.push({id, x, y});
        } else {
            if (x == st.top().x) {
                continue;
            } else {
                while (!st.empty() && y <= st.top().y) {
                    st.pop();
                }
                st.push({id, x, y});
            }
        }
    }

    vector<PII> p;
    while (!st.empty()) {
        auto [id, x, y] = st.top();
        st.pop();
        add[id] = 1;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end());

    LL area = p[0].first * (m - p[0].second + 1);
    for (int i = 1; i < p.size(); i++) {
        area += (m - p[i].second + 1) * (p[i].first - p[i - 1].first);
    }
    cout << n * m - area << '\n';

    for (auto x : add) {
        cout << x << ' ';
    }
    cout << '\n';
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