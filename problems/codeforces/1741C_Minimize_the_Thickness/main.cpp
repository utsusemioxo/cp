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

int go(int i, int sum, vector<long long> input) {
    if (i == input.size()) {
        return 0;
    }

    for (int j = i + 1, cur = 0; j <= input.size(); ++j) {
        cur += input[j - 1];
        if (cur > sum) return input.size();
        if (cur == sum) return max(j - i, go(j, sum, input));
    }

    return input.size();
}

int solve(std::vector<long long> input) {
    int ans = input.size();

    for (int len = 1, sum = 0; len < input.size(); ++len) {
      sum += input[len - 1];
      ans = min(ans, go(0, sum, input));
    }

    return ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> input(n);
        for (auto & i : input) {
            cin >> i;
        }

        cout << solve(input) << endl;
    }
}
