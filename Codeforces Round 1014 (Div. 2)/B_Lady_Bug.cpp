#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int comp1 = 0, comp2 = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0) { 
            if (a[i] == '1') {
                comp1++;

            }
            if (b[i] == '1') {
                comp2++;
            }
        } else { 
            if (b[i] == '1') {
                comp1++;
            }
            if (a[i] == '1') {
                comp2++;
            }
        }
    }

    int cap1 = n / 2;
    int cap2 = n - cap1;
    
    if (comp1 <= cap1 && comp2 <= cap2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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