#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, ans;
        scanf("%d%d%d", &a, &b, &c);
        if (abs(b - a) % (2 * c) == 0)
            ans = abs(b - a) / c / 2;
        else
            ans = abs(b - a) / c / 2 + 1;
        printf("%d\n", ans);
    }
    return 0;
}