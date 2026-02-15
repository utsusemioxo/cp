#include <iostream>
#include <utility>
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
    int num_digits = 0;
    cin >> num_digits;

    vector<int> digits_res(num_digits);
    for (auto & i : digits_res) {
        cin >> i;
    }

    vector<pair<int, string>> actions(num_digits);
    for (auto & pair : actions) {
        cin >> pair.first;
        cin >> pair.second;
    }

    vector<int> digits_origin(num_digits);
    for (int i = 0; i < num_digits; ++i) {
        digits_origin[i] = digits_res[i];
    }

    for (int i = 0; i < num_digits; i++) {
        auto action_string = actions[i].second;
        for (int j = 0; j < actions[i].first; j++) {
            char action = action_string[j];
            if (action == 'U') {
                digits_origin[i] -= 1;
                if (digits_origin[i] < 0) digits_origin[i] += 10;
                if (digits_origin[i] > 9) digits_origin[i] -= 10;
            } else if (action == 'D'){
                digits_origin[i] += 1;
                if (digits_origin[i] < 0) digits_origin[i] += 10;
                if (digits_origin[i] > 9) digits_origin[i] -= 10;
            } else {
                cout << "\nerror\n";
            }
        }
    }

    for (auto digit : digits_origin) {
        cout << digit << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
