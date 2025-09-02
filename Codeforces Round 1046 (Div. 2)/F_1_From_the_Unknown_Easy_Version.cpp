#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5;

int check(int x) {
    int le = 1, ri = N, mid;
    int res = 0;
    while (le <= ri) {
        mid = (le + ri) / 2;
        if ((N + mid - 1) / mid >= x) {
            res = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }
    return res;
}

void solve() {
    cout << "? " << N;
    for (int i = 0; i < N; i++) {
        cout << ' ' << 1;
    }
    cout << endl;
    int x;
    cin >> x;
    int l = check(x + 1) + 1, r = check(x);
    if (l == r) {
        cout << "! " << l << endl;
        return;
    } 
    // cout << l << ' ' << r << endl;

    cout << "? " << 2 * (r - l);
    for (int i = 1; i <= r - l; i++) {
        cout << ' ' << l << ' ' << i;
    }
    cout << endl;
    cin >> x;
    cout << "! " << l + 2 * (r - l) - x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("out.txt", "w", stdout);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}