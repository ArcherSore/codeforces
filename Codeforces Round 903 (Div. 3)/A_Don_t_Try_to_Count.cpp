#include <bits/stdc++.h>
using namespace std;

bool is_substr(string &s1, string &s2) {
    for (int i = 0; i <= s1.size() - s2.size(); i++) {
        if (s2 == s1.substr(i, s2.size()))
            return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        int cnt = 0;
        while (s1.size() < s2.size()) {
            s1 += s1;
            cnt++;
        }
        if (is_substr(s1, s2)) {
            cout << cnt << endl;
            continue;
        }
        s1 += s1;
        cnt++;
        if (is_substr(s1, s2)) {
            cout << cnt << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}