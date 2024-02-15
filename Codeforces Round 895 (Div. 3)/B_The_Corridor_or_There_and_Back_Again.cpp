#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = INT32_MAX;
        cin >> n;
        while (n--) {
            int d, s, move;
            scanf("%d%d", &d, &s);
            move = d + (s - 1) / 2;
            ans = min(ans, move);
        }
        printf("%d\n", ans);
    }
    return 0;
}