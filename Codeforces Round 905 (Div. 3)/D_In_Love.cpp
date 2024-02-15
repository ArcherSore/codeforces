#include <map>
#include <iostream>
using namespace std;

struct Node {
    int l, r;
    bool operator<(const struct Node &right)const {
        if (this->l != right.l) {
            return this->l < right.l;
        } else {
            return this->r < right.r;
        }
    }
};

map<Node, int> seg;


bool exist() {
    auto it = seg.begin();
    auto next_it = std::next(it);
    
    while (next_it != seg.end()) {
        if (it->first.r >= next_it->first.l) {
            return true;  // There is an overlap
        }
        ++it;
        ++next_it;
    }
    
    return false;  // No overlap found
}

void output() {
    for (auto x : seg) {
        cout << x.first.l << " " << x.first.r << endl;
    }
}

void solve() {
    char opt;
    int a, b;
    cin >> opt >> a >> b;
    if (opt == '+') {
        seg[{a, b}]++;
    } else {
        seg[{a, b}]--;
        if (seg[{a, b}] == 0) {
            seg.erase({a, b});
        }
    }
    // output();
    if (exist()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}