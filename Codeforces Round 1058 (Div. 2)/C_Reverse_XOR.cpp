#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> work(int x) {
    vector<int> bits;
    while (x) {
        bits.push_back(x & 1);
        x >>= 1;
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

int f(int x) {
    vector<int> bits = work(x);
    while (!bits.empty() && bits.back() == 0) {
        bits.pop_back();
    }
    reverse(bits.begin(), bits.end());
    int res = 0;
    for (auto x : bits) {
        res <<= 1;
        res |= x;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> bits = work(n);
    int cnt = count(bits.begin(), bits.end(), 1);
    if (cnt & 1) {
        cout << "NO\n";
        return;
    }
    if (n & 1) {
        int l = 0, r = bits.size() - 1;
        while (l <= r) {
            if (bits[l] != bits[r]) {
                cout << "NO\n";
                return;
            }
            l++, r--;
        }
        cout << "YES\n";
    } else {
        int cnt0 = 0;
        reverse(bits.begin(), bits.end());
        for (auto x : bits) {
            if (x == 1) {
                break;
            }
            cnt0++;
        }
        // if (bits.size() + cnt0 > 30) {
        //     cout << "NO\n";
        //     return;
        // }
        reverse(bits.begin(), bits.end());
        while (!bits.empty() && bits.back() == 0) {
            bits.pop_back();
        }
        int l = 0, r = bits.size() - 1;
        while (l <= r) {
            if (bits[l] != bits[r]) {
                cout << "NO\n";
                return;
            }
            l++, r--;
        }
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("out.txt", "w", stdout);

    // set<int> s;
    // for (int i = 1; i <= 1000; i++) {
    //     s.insert(i ^ f(i));
    // }
    // for (auto x : s) {
    //     vector<int> bits = work(x);
    //     for (auto x : bits) {
    //         cout << x;
    //     }
    //     cout << '\n';
    // }

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}