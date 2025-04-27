#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL x, y, d;

void query1(LL lvl, LL st, LL sx, LL sy) {
    if (lvl == 1) {
        if (x == sx && y == sy) {
            cout << st << "\n";
        } else if (x == sx + 1 && y == sy + 1) {
            cout << st + 1 << "\n";
        } else if (x == sx + 1 && y == sy) {
            cout << st + 2 << "\n";
        } else {
            cout << st + 3 << "\n";
        }
        return;
    }
    LL mid = 1LL << (lvl - 1);
    LL sz = 1LL << (2 * (lvl - 1));
    
    LL rx = x - sx;
    LL ry = y - sy;

    if (rx < mid && ry < mid) {
        query1(lvl - 1, st, sx, sy);
    } else if (rx >= mid && ry >= mid) {
        query1(lvl - 1, st + sz, sx + mid, sy + mid);
    } else if (rx >= mid && ry < mid) {
        query1(lvl - 1, st + 2 * sz, sx + mid, sy);
    } else {
        query1(lvl - 1, st + 3 * sz, sx, sy + mid);
    }
}

void query2(LL lvl, LL st, LL sx, LL sy) {
    if (lvl == 1) {
        if (d == st) {
            cout << sx << " " << sy << "\n";
        } else if (d == st + 1) {
            cout << sx + 1 << " " << sy + 1 << "\n";
        } else if (d == st + 2) {
            cout << sx + 1 << " " << sy << "\n";
        } else {
            cout << sx << " " << sy + 1 << "\n";
        }
        return;
    }
    LL mid = 1LL << (lvl - 1);
    LL sz = 1LL << (2 * (lvl - 1));
    
    if (d < st + sz) {
        query2(lvl - 1, st, sx, sy);
    } else if (d < st + 2 * sz) {
        query2(lvl - 1, st + sz, sx + mid, sy + mid);
    } else if (d < st + 3 * sz) {
        query2(lvl - 1, st + 2 * sz, sx + mid, sy);
    } else {
        query2(lvl - 1, st + 3 * sz, sx, sy + mid);
    }
}

void solve() {
    LL n;
    cin >> n;
    LL q;
    cin >> q;
    while (q--) {
        string op;
        cin >> op;
        if (op == "->") {
            cin >> x >> y;
            query1(n, 1, 1, 1);
        } else {
            cin >> d;
            query2(n, 1, 1, 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}