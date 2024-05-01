#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        string s;
        cin >> s;
        int cnt = 0;
        for (auto c : s) {
            if (c == 'U') {
            cnt++;
            }
        }
        if (cnt% 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}