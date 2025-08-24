#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Pos {
    int id, x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<Pos> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    }
    sort(p.begin(), p.end(), [](const Pos &a, const Pos &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    });
    sort(p.begin(), p.begin() + n / 2, [](const Pos &a, const Pos &b) {
        return a.y < b.y;
    });
    sort(p.begin() + n / 2, p.end(), [](const Pos &a, const Pos &b) {
        return a.y < b.y;
    });
    for (int i = 0; i < n / 2; i++) {
        cout << p[i].id << ' ' << p[n - i - 1].id << '\n';
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