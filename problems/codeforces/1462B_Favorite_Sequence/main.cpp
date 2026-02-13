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

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    vector<long long> out(n);

    long long l = 0;
    long long r = n - 1;
    long long index = 0;
    while (l <= r && index < n) {
        out[index++] = a[l++];
        if (index >= n) break;
        out[index++] = a[r--];
        if (index >= n) break;

    }

    for (auto x : out) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
