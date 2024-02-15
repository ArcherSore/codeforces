#include <bits/stdc++.h>
using namespace std;

bool equal(vector<int> &v) {
    int t = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != t)
            return false;
    }
    return true;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v;
    v.push_back(a), v.push_back(b), v.push_back(c);
    
    for (int i = 0; i < 3; i++) {
        if (equal(v)) {
            cout << "YES" << endl;
            return;
        }
        int maxx = v[0], minn = v[0], max_id = 0;
        for (int j = 1; j < v.size(); j++) {
            minn = min(minn, v[j]);
            if (v[j] > maxx) {
                maxx = v[j];
                max_id = j;
            }
        }
        v[max_id] = maxx - minn;
        v.push_back(minn);
    }
    if (equal(v)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}