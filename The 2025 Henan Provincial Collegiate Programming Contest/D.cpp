#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int sq = sqrt(n);
    if (sq * sq != n) {
        cout << "No\n";
        return 0;
    }
    int tot = 0;
    while (n) {
        tot += n % 10;
        n /= 10;
    }
    sq = sqrt(tot);
    if (sq * sq != tot) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    return 0;
}

// 5:38