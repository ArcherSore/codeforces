#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, r;
    cin >> n;
    set<int> leaf;
    vector<int> p(n, -1);
    p[1] = 0;
    for (int i = 2; i < n; i++) {
        cout << "? 1 " << i << endl;
        cin >> r;
        if (r == 0) {
            p[i] = 1;
            leaf.insert(i);
            break;
        } else {
            p[i] = 0;
            leaf.insert(i);
        }
    }
    int maxp = 0;
    auto rem = [&](int i) -> void {
        vector<int> tmp;
        for (auto j : leaf) {
            if (j < maxp) {
                tmp.push_back(j);
            }
        }
        for (auto x : tmp) {
            leaf.erase(x);
        }
    };
    for (int i = 2; i < n; i++) {
        if (p[i] != -1) {
            continue;
        }
        rem(i);
        for (auto j : leaf) {
            cout << "? " << j << ' ' << i << endl;
            cin >> r;
            if (r == 0) {
                p[i] = j;
                leaf.erase(j);
                leaf.insert(i);
                maxp = max(maxp, p[i]);
                break;
            }
        }
        if (p[i] == -1) {
            p[i] = 0;
            leaf.insert(i);
        }
    }
    cout << "!";
    for (int i = 1; i < n; i++) {
        cout << " " << p[i];
    }
    cout << endl;
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