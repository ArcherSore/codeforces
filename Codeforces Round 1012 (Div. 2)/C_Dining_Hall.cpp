#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<array<int, 3>> seats;

void init() {
    int n = 320;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = 3 * i + 1, y = 3 * j + 1;
            seats.push_back({x + y - 1, x, y});
            seats.push_back({x + y, x + 1, y});
            seats.push_back({x + y, x, y + 1});
            seats.push_back({x + y + 3, x + 1, y + 1});
        }
    }
    sort(seats.begin(), seats.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (auto &x : t) {
        cin >> x;
    }

    int m = sqrt(n * 2) + 10;
    vector<vector<int>> cell(3 * m, vector<int> (3 * m));
    vector<vector<int>> table(m, vector<int> (m));
    int p0 = 0, p1 = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        if (t[i] == 0) {
            while (table[seats[p0][1] / 3][seats[p0][2] / 3]) {
                p0++;
            }
            x = seats[p0][1], y = seats[p0][2];
        } else {
            while (cell[seats[p1][1]][seats[p1][2]]) {
                p1++;
            }
            x = seats[p1][1], y = seats[p1][2];
        }
        cell[x][y] = 1;
        table[x / 3][y / 3] = 1;
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    init();

    while (T--) {
        solve();
    }

    return 0;
}