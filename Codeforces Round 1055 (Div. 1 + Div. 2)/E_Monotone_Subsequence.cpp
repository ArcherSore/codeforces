#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void query(set<int> &s) {
    cout << "? " << s.size() << ' ';
    for (auto &x : s) {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> answer() {
    int n;
    cin >> n;
    vector<int> res(n);
    for (auto &x : res) {
        cin >> x;
    }
    return res;
}

void output(const vector<int> &res) {
    cout << '!';
    for (auto &x : res) {
        cout << ' ' << x;
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n * n + 1; i++) {
        s.insert(i);
    }

    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        query(s);
        v[i] = answer();
        if (v[i].size() >= n + 1) {
            output(vector<int>(v[i].begin(), v[i].begin() + n + 1));
            return;
        }
        for (auto x : v[i]) {
            s.erase(x);
        }
    }
    v[n].reserve(s.size());
    for (auto x : s) {
        v[n].push_back(x);
        // cerr << x << ' ';
    }
    // cerr << '\n';

    int cur = n * n + 2;
    vector<int> res(n + 1);
    for (int i = n; i >= 0; i--) {
        for (int k = v[i].size() - 1; k >= 0; k--) {
            if (v[i][k] < cur) {
                res[i] = v[i][k];
                cur = res[i];
                break;
            }
        }
    }
    output(res);
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