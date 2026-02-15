#include <array>
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

    vector<int> input(n);
    for (auto &i : input) {
        cin >> i;
    }

    vector<int> cnt(n + 1);

    for (auto i : input) {
        if (i >= 1 && i <= n)
            cnt[i]++;
    }

    bool has_res = false;
    for (int i = 1; i < cnt.size(); i++) {
        if (cnt[i] >= 3) {
            cout << i << endl;
            has_res = true;
            break;
        }
    }
    if (!has_res)
        cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
