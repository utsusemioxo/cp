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

bool checkValidChar(const char c) {
    if (c != 'T' && c != 'i' && c != 'm' && c != 'u' && c != 'r')
        return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool correct = false;    

    unordered_map<char, int> stat = {};
    if (n != 5) {
        correct = false;
        cout << "NO" << endl;
        return;
    }

    for (char c : s) {
        if (!checkValidChar(c)) {
            cout << "NO" << endl;
            return;
        }
        stat[c]++;
    }

    if (stat['T'] == 1 && stat['i'] == 1 && stat['m'] == 1 && stat['u'] == 1 && stat['r'] == 1) {
        cout << "YES" << endl;
        return;
    } else {
        cout << "NO" << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
