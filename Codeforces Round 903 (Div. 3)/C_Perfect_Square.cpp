#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char a[MAXN][MAXN];

int replace(int i, int j, int n) {
    int cnt = 0, tmp_x, tmp_y;
    vector<char> v;
    char max_char = 'a';
    for (int k = 0; k < 4; k++) {
        v.push_back(a[i][j]);
        max_char = max(max_char, a[i][j]);
        tmp_x = j, tmp_y = n + 1 - i;
        i = tmp_x, j = tmp_y;
    }
    for (int i = 0; i < 4; i++) {
        cnt += (max_char - v[i]);
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n / 2; i++) {
            for (int j = i; j <= n - i; j++) {
                cnt += replace(i, j, n);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}