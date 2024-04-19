#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int MAXN = 2e5 + 10;

void init(string &s, vector<int> &f1, vector<int> &f2) {
    int n = s.size() - 1;
    // equal
    for (int i = 0; s[i]; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            f1[i] = i;
        } else {
            f1[i] = f1[i - 1];
        }
    }
    // intersection
    for (int i = 0; s[i]; i++) {
        if (i == 0 || i == 1 || s[i] != s[i - 2]) {
            f2[i] = i;
        } else {
            f2[i] = f2[i - 2];
        }
    }
}

vector<int> manacher(string &s) {
    // 创建新的字符串t，其中每个字符之间都插入了'#'
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }

    int n = t.size();
    // 初始化d数组，d[i]表示以字符t[i]为中心的最长回文子串的半径（包括t[i]本身）
    vector<int> d(n);

    // j是当前已知的所有回文子串中，最靠右的那个回文子串的中心位置
    // j + d[j]是最靠右的那个回文子串的右边界
    for (int i = 0, j = 0; i < n; i++) {
        // 利用对称性，如果i在已知的最右边界之内，那么可以直接得到d[i]的一个初值
        if (2 * j - i >= 0 && j + d[j] > i) {
            d[i] = min(d[2 * j - i], j + d[j] - i);
        }
        // 尝试扩展以t[i]为中心的回文子串
        while (i - d[i] >= 0 && i + d[i] < n && t[i - d[i]] == t[i + d[i]]) {
            d[i] += 1;
        }
        // 如果通过扩展，以t[i]为中心的回文子串的右边界超过了当前的最右边界，那么就更新中心位置j
        if (i + d[i] > j + d[j]) {
            j = i;
        }
    }
    // 返回d数组，其中d[i]表示以字符t[i]为中心的最长回文子串的半径（包括t[i]本身）
    return d;
}

LL f(int l, int r, vector<int> &f1, vector<int> &f2, vector<int> &d) {
    LL res = 0, add;
    int n = r - l + 1;
    // k = 1
    res += 1;
    // k = n
    if (d[l + r + 1] > n) {
        res += n;
    }
    // 1 < k < n && k is even 
    if (f1[r] <= l) {
        if (n % 2) {
            add = 1LL * (2 + n - 1) * (n / 2) / 2;
        } else {
            add = 1LL * (2 + n - 2) * (n / 2 - 1) / 2;
        }
        res += add;
    }
    // 1 < k < n && k is odd
    if (n % 2) {
        if (f2[r] <= l && f2[r - 1] <= l + 1) {
            add = 1LL * (3 + n - 2) * (n / 2 - 1) / 2;
            res += add;
        }
    } else {
        if (f2[r] <= l + 1 && f2[r - 1] <= l) {
            add = 1LL * (3 + n - 1) * ((n - 1) / 2) / 2;
            res += add;
        }
    }
    
    return 1LL * (1 + n) * n / 2 - res;
}

void solve() {
    LL n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> f1(n), f2(n), d(n);

    init(s, f1, f2);
    d = manacher(s);

    while (q--) {
        LL l, r;
        cin >> l >> r;
        string t = s.substr(l - 1, r - l + 1);
        cout << f(l - 1, r - 1, f1, f2, d) << '\n';
    }
    return;
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