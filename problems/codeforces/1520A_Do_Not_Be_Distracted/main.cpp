#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <array>
#include <limits>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    array<bool, 26> seen = {};
    char last_seen {};
    for (char c : s) {
        if (!seen[c - 'A']) {
            seen[c - 'A'] = true;
        } else if (seen[c - 'A'] && last_seen != c) {
            cout << "NO" << endl;
            return;
        } else {
            
        }
        last_seen = c;
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
