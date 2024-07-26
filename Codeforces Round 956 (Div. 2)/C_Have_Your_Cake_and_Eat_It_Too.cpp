// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<LL> suma(n + 1), sumb(n + 1), sumc(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma[i] = suma[i - 1] + 1LL * a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sumb[i] = sumb[i - 1] + 1LL * b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sumc[i] = sumc[i - 1] + 1LL * c[i];
    }

    LL std = (suma[n] + 2) / 3;
    int c1, c2, c3;

    c1 = -1, c2 = -1, c3 = -1;
    for (int i = 1; i <= n; i++) {
        if (c1 == -1) {
            if (suma[i] >= std) {
                c1 = i;
            }
        } else if (c2 == -1) {
            if (sumb[i] - sumb[c1] >= std) {
                c2 = i;
            }
        } else if (c3 == -1) {
            if (sumc[n] - sumc[c2] >= std) {
                c3 = n;
                cout << 1 << " " << c1 << " " << c1 + 1 << " " << c2 << " " << c2 + 1 << " " << c3 << '\n';
                return;
            }
        }
    }

    c1 = -1, c2 = -1, c3 = -1;
    for (int i = 1; i <= n; i++) {
        if (c1 == -1) {
            if (suma[i] >= std) {
                c1 = i;
            }
        } else if (c3 == -1) {
            if (sumc[i] - sumc[c1] >= std) {
                c3 = i;
            }
        } else if (c2 == -1) {
            if (sumb[n] - sumb[c3] >= std) {
                c2 = n;
                cout << 1 << " " << c1 << " " << c3 + 1 << " " << c2 << " " << c1 + 1 << " " << c3 << '\n';
                return;
            }
        }
    }

    c1 = -1, c2 = -1, c3 = -1;
    for (int i = 1; i <= n; i++) {
        if (c2 == -1) {
            if (sumb[i] >= std) {
                c2 = i;
            }
        } else if (c1 == -1) {
            if (suma[i] - suma[c2] >= std) {
                c1 = i;
            }
        } else if (c3 == -1) {
            if (sumc[n] - sumc[c1] >= std) {
                c3 = n;
                cout << c2 + 1 << " " << c1 << " " << 1 << " " << c2 << " " << c1 + 1 << " " << c3 << '\n';
                return;
            }
        }
    }

    c1 = -1, c2 = -1, c3 = -1;
    for (int i = 1; i <= n; i++) {
        if (c2 == -1) {
            if (sumb[i] >= std) {
                c2 = i;
            }
        } else if (c3 == -1) {
            if (sumc[i] - sumc[c2] >= std) {
                c3 = i;
            }
        } else if (c1 == -1) {
            if (suma[n] - suma[c3] >= std) {
                c1 = n;
                cout << c3 + 1 << " " << c1 << " " << 1 << " " << c2 << " " << c2 + 1 << " " << c3 << '\n';
                return;
            }
        }
    }

    c1 = -1, c2 = -1, c3 = -1;
    for (int i = 1; i <= n; i++) {
        if (c3 == -1) {
            if (sumc[i] >= std) {
                c3 = i;
            }
        } else if (c1 == -1) {
            if (suma[i] - suma[c3] >= std) {
                c1 = i;
            }
        } else if (c2 == -1) {
            if (sumb[n] - sumb[c1] >= std) {
                c2 = n;
                cout << c3 + 1 << " " << c1 << " " << c1 + 1 << " " << c2 << " " << 1 << " " << c3 << '\n';
                return;
            }
        }
    }

    c1 = -1, c2 = -1, c3 = -1;
    for (int i = 1; i <= n; i++) {
        if (c3 == -1) {
            if (sumc[i] >= std) {
                c3 = i;
            }
        } else if (c2 == -1) {
            if (sumb[i] - sumb[c3] >= std) {
                c2 = i;
            }
        } else if (c1 == -1) {
            if (suma[n] - suma[c2] >= std) {
                c1 = n;
                cout << c2 + 1 << " " << c1 << " " << c3 + 1 << " " << c2 << " " << 1 << " " << c3 << '\n';
                return;
            }
        }
    }

    cout << -1 << '\n';
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