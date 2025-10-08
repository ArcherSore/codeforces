#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const double pi = atan2(0, -1);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> arc(2 * n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        arc[i] = atan2(y, x);
    }
    sort(arc.begin(), arc.begin() + n);

    for (int i = n; i < 2 * n; i++) {
        arc[i] = arc[i - n] + 2 * pi;
    }
    
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res = max(res, arc[i + k] - arc[i]);
    }
    cout << fixed << setprecision(10) << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}