#include <bits/stdc++.h>
using namespace std;

void solve(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (i > 2 && i % 2 == 0) {
            printf("%d %d\n", 2, i - 2);
            return;
        }
    }
    if (l == r) {
        for (int i = 3; i <= sqrt(l); i++) {
            if (l % i == 0) {
                printf("%d %d\n", i, l - i);
                return;
            }
        }
    }
    printf("-1\n");
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        solve(l, r); 
    }
    return 0;
}