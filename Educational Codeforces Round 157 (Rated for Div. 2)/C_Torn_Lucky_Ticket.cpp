#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > cnt(6, vector<int> (50)); // 记录每个长度的数字和的个数
    vector<vector<int> > sum(n, vector<int> (6)); // 记录每个数字的前各位数字和
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int len = s.size(), sumx = 0;
        sum[i][0] = len; // 存储第i个数字的长度
        for (int j = 0; j < len; j++) {
            sumx += s[j] - '0';
            sum[i][j + 1] = sumx;
        }
        // cout << sum << endl;
        cnt[len][sumx]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int len = sum[i][0];
        sum[i][0] = 0;
        for (int j = (len & 1); j <= len; j += 2) {
            if (j == 0) continue;
            int half = (len + j) / 2;
            if (len == j)
                ans += cnt[len][sum[i][half]];
            else {
                ans += cnt[j][sum[i][half] + sum[i][half] - sum[i][len]];
                ans += cnt[j][sum[i][len] - 2 * sum[i][half - j]];
            }
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}