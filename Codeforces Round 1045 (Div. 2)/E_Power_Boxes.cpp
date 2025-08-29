#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

/*
    can easily determine the last two within 3 operations

    x x 1 1 t2 .
    x x 1 2 t2 *
    x x 2 1 t1 -> s1 -> t1 .
    x x 2 2 t1 -> s1 -> t1 .*
    can easily determine the last four within 6 operations, but stop at different positions

    to build on the nearest two, record the the jumps of 3-rd and 4-th
    1 1 2 2 j1 j2 t1[3+j1] -> s1 -> t1[3+j1]
    1 2 2 2 j1 j2 t1[3+j2] -> s1 -> t1[2+j1]
    2 1 2 2 j1 j2 t1[2+j1] -> s1 -> t1[3+j2]
    2 2 2 2 j1 j2 t1[2+j1] -> s1 -> t1[2+j1]

    1 1 2 2 j1 j2 t2[2+j1] -> s1 -> t2[2+j1]
    1 2 2 2 j1 j2 t2[2+j2] -> s1 -> t2[2+j1]
    2 1 2 2 j1 j2 t2[2+j1] -> s1 -> t2[2+j2]
    2 2 2 2 j1 j2 t2[2+j2] -> s1 -> t2[2+j2]
    
    #1 j1 == j2 + 1 t1 -> s1 -> t1
    #2 j1 != j2 + 1 t2 -> s1 -> t2
*/

pii last2(int n) {
    pii res;
    int j;
    cout << "throw " << n - 1 << endl;
    cin >> j;
    res.first = (j == 1 ? 2 : 1);
    cout << "swap " << n - 1 << endl;
    cout << "throw " << n - 1 << endl;
    cin >> j;
    res.second = (j == 1 ? 2 : 1);
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = {i, -1};
    }
    // determine the last two (in initial order)
    pii ls2 = last2(n);
    res[n - 2].second = ls2.first, res[n - 1].second = ls2.second;
    swap(res[n - 2], res[n - 1]);

    auto jump = [&](int x) -> int {
        int c = 0;
        while (x < n) {
            c++;
            x += res[x].second;
        }  
        return c;
    };

    // cout << "!";
    // for (auto [idx, x] : res) {
    //     cout << " " << x; 
    // }
    // cout << endl;

    // int j1 = (res[n - 2].second == 2 ? 1 : 2);
    // int j2 = 1;
    int i = n - 4;
    while (i >= 0) {
        int j1 = jump(i + 4), j2 = jump(i + 5);
        if (res[i + 2].second == 1 && res[i + 3].second == 1) {
            cout << "throw " << i + 2 << endl;
            int j;
            cin >> j;
            if (j == 3 + j1) {
                res[i + 1].second = 1;
            } else {
                res[i + 1].second = 2;
            }
            i--;
        } else if (res[i + 2].second == 1 && res[i + 3].second == 2) {
            cout << "throw " << i + 2 << endl;
            int j;
            cin >> j;
            if (j == 3 + j2) {
                res[i + 1].second = 1;
            } else {
                res[i + 1].second = 2;
            }
            i--;
        } else if (res[i + 2].second == 2 && res[i + 3].second == 1) {
            cout << "throw " << i + 1 << endl;
            int j;
            cin >> j;
            if (j == 3 + j1) {
                res[i].second = 1;
            } else {
                res[i].second = 2;
            }
            cout << "swap " << i + 1 << endl;
            swap(res[i], res[i + 1]);
            cout << "throw " << i + 1 << endl;
            cin >> j;
            if (j == 3 + j1) {
                res[i].second = 1;
            } else {
                res[i].second = 2;
            }
            i -= 2;
        } else {
            if (j1 == j2) {
                cout << "throw " << i + 1 << endl;
                int j, jj;
                cin >> j;
                cout << "swap " << i + 1 << endl;
                cout << "throw " << i + 1 << endl;
                cin >> jj;
                if (j == 3 + j1 && jj == 3 + j1) {
                    res[i].second = res[i + 1].second = 1;
                } else if (j == 3 + j2 && jj == 2 + j1) {
                    res[i].second = 1;
                    res[i + 1].second = 2;
                } else if (j == 2 + j1 && jj == 3 + j2) {
                    res[i].second = 2;
                    res[i + 1].second = 1;
                } else {
                    res[i].second = res[i + 1].second = 2;
                }
                swap(res[i], res[i + 1]);
            } else {
                cout << "throw " << i + 2 << endl;
                int j, jj;
                cin >> j;
                cout << "swap " << i + 1 << endl;
                cout << "throw " << i + 2 << endl;
                cin >> jj;
                if (j == 2 + j1 && jj == 2 + j1) {
                    res[i].second = res[i + 1].second = 1;
                } else if (j == 2 + j2 && jj == 2 + j1) {
                    res[i].second = 1;
                    res[i + 1].second = 2;
                } else if (j == 2 + j1 && jj == 2 + j2) {
                    res[i].second = 2;
                    res[i + 1].second = 1;
                } else {
                    res[i].second = res[i + 1].second = 2;
                }
                swap(res[i], res[i + 1]);
            }
            i -= 2;
        }
    }

    if (res[0].second == -1) {
        // if j1 == j2, have to swap some x to make j1 & j2 different?
        int j1 = jump(1), j2 = jump(2);
        if (j1 != j2) {
            int j;
            cout << "throw 1" << endl;
            cin >> j;
            if (j == 1 + j1) {
                res[0].second = 1;
            } else {
                res[0].second = 2;
            }
        } else {
            int j;
            cout << "swap 1" << endl;
            swap(res[0], res[1]);
            cout << "throw 2" << endl;
            cin >> j;
            j1 = jump(2), j2 = jump(3);
            if (j == 1 + j1) {
                res[1].second = 1;
            } else {
                res[1].second = 2;
            }
        }
    }

    sort(res.begin(), res.end());
    cout << "!";
    for (auto [idx, x] : res) {
        cout << " " << x; 
    }
    cout << endl;
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