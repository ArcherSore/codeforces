#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void query(vector<int> &seq) {
    cout << "? " << seq.size();
    for (auto x : seq) {
        cout << ' ' << x;
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> seq;
    vector<int> res(2 * n);
    seq.push_back(1);
    for (int i = 1; i < 2 * n; i++) {
        seq.push_back(i + 1);
        query(seq);
        
        int ans;
        cin >> ans;
        if (ans != 0) {
            res[i] = ans;
            seq.pop_back();
        }
    }
    // for (auto x : res) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';
    seq.clear();
    for (int i = 0; i < 2 * n; i++) {
        if (res[i] != 0) {
            seq.push_back(i + 1);
        }
    }
    // for (auto x : seq) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';
    for (int i = 0; i < 2 * n; i++) {
        if (res[i] != 0) {
            continue;
        }
        seq.push_back(i + 1);
        query(seq);

        int ans;
        cin >> ans;
        res[i] = ans;

        seq.pop_back();
    }

    cout << "!";
    for (auto x : res) {
        cout << ' ' << x;
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