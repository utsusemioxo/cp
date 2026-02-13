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
#include <limits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    // Your code here
    unordered_set<char> balloons_gotten; 
    int ans = 0;

    string s;
    cin >> s;
    for (const auto c : s) {
        if (balloons_gotten.contains(c)) {
            ans ++;
        } else {
            ans += 2;
            balloons_gotten.insert(c);
        }
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
