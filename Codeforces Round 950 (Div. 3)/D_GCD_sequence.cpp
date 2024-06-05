#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void find_cut_points(const vector<int>& g, int &cut, vector<int>& positions) {
    for (int i = 1; i < g.size(); i++) {
        if (g[i] < g[i - 1]) {
            cut++;
            positions.push_back(i);
        }
    }
}

bool check(vector<int> &a, int p) {
    int n = a.size();
    if (p < 0 || p + 1 > n) {
        return false;
    }

    vector<int> g(n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (i == p) {
            continue;
        }
        if (i < p - 1) {
            g[i] = gcd(a[i], a[i + 1]);
        } else if (i == p - 1) {
            g[i] = gcd(a[i], a[i + 2]);
        } else {
            g[i - 1] = gcd(a[i], a[i + 1]);
        }
    }
    for (int i = 1; i < n - 2; i++) {
        if (g[i] < g[i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 3) {
        cout << "YES\n";
        return;
    }

    vector<int> g(n - 1);
    for (int i = 0; i < n - 1; i++) {
        g[i] = gcd(a[i], a[i + 1]);
    }

    int cut = 0;
    vector<int> positions;
    find_cut_points(g, cut, positions);

    if (cut == 0) {
        cout << "YES\n";
    } else if (cut == 1) {
        int p = positions[0];
        if (check(a, p - 1) || check(a, p) || check(a, p + 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (cut == 2) {
        if (positions[1] - positions[0] <= 2) {
            int p = positions[0];
            if (check(a, p) || check(a, p + 1) || check(a, p + 2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
