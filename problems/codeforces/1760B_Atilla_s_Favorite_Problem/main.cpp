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

    string s;
    cin >> s;

    auto ans = 0;

    for (char c : s) {
        ans = max(ans, c - 'a');
    }

    cout << ans+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
