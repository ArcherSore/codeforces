#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], pre1[MAXN] = {0}, pre0[MAXN] = {0}; 
string s;

void replace_s(int l, int r) {
    for (int i = l - 1; i < r; i++) {
        if (s[i] - '0' == 0)
            s[i] = '1';
        else s[i] = '0';
    }
    return;
}

void find_xor(int x, int n) {
    int ans = 0, first = 1;
    for (int i = 1; i <= n; i++) {
        if ((s[i - 1] - '0') == i) {
            if (first) {
                ans = a[i];
                first = 0;
            } else {
                ans ^= a[i];
            }
        }
    }
    printf("%d\n", ans);
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        cin >> s;
        cin >> q;
        while (q--) {
            int type;
            scanf("%d", &type);
            if (type) {
                int l, r;
                scanf("%d%d", &l, &r);
                replace_s(l, r);
            } else {
                int x;
                scanf("%d", &x);
                find_xor(x, n);
            }
        }  
    }
    return 0;
}