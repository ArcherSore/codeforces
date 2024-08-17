#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

template <typename T>
vector<int> generatePattern(const T& seq) {
    map<typename T::value_type, int> index_map;
    vector<int> pattern(seq.size());
    int current_index = 0;
    
    for (size_t i = 0; i < seq.size(); ++i) {
        if (index_map.find(seq[i]) == index_map.end()) {
            index_map[seq[i]] = current_index++;
        }
        pattern[i] = index_map[seq[i]];
    }
    
    return pattern;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int m;
        cin >> m;
        vector<string> strings(m);
        for (int i = 0; i < m; ++i) {
            cin >> strings[i];
        }
        
        vector<int> template_pattern = generatePattern(a);
        
        for (int i = 0; i < m; ++i) {
            if (strings[i].size() != n) {
                cout << "NO\n";
                continue;
            }
            
            vector<int> string_pattern = generatePattern(strings[i]);
            
            // Compare patterns
            if (template_pattern == string_pattern) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
