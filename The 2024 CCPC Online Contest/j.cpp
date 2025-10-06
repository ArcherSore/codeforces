#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int A = 0, B = 0;
    for (auto &x : a) cin >> x, A ^= x;
    for (auto &x : b) cin >> x, B ^= x;

    vector<int> basis(31);
    for (int i = 0; i < n; i++) {
        int t = a[i] ^ b[i];
        for (int i = 30; i >= 0; i--) {
            if (t >> i & 1) {
                if (basis[i] == 0) {
                    basis[i] = t;
                    break;
                }
                t ^= basis[i];
            }
        }
    }

    int flag = 0;
    for (int i = 30; i >= 0; i--) {
        if (flag == 1) {
            if ((A >> i & 1) && basis[i]) {
                A ^= basis[i];
                B ^= basis[i];
            }
        } else if (flag == 2) {
            if ((B >> i & 1) && basis[i]) {
                A ^= basis[i];
                B ^= basis[i];
            }
        } else {
            if ((A >> i & 1) && (B >> i & 1)) {
                if (basis[i]) {
                    A ^= basis[i];
                    B ^= basis[i];
                }
            } else if (A >> i & 1) {
                flag = 1;
            } else if (B >> i & 1) {
                flag = 2;
            }
        }
    }

    cout << max(A, B) << '\n';
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