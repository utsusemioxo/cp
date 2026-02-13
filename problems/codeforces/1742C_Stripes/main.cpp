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

constexpr int WIDTH = 8;
constexpr int HEIGHT = 8;

void print(array<array<char, 8>, 8> grid) {
    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            cout << grid[h][w];
        }
        cout << endl;
    }
}

void solve() {
    array<array<char, WIDTH>, HEIGHT> grid;
    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            cin >> grid[h][w];
        }
    }

    // print(grid);
    bool allR = false;
    for (int h = 0; h < HEIGHT; h++) {
        int cnt_r = 0;
        for (int w = 0; w < WIDTH; w++) {
            if (grid[h][w] == 'R')
                cnt_r++;
        }
        if (cnt_r == WIDTH) {
            allR = true;
            break;
        } else {
            continue;
        }
    }

    if (allR) {
        cout << "R" << endl;
    } else {
        cout << "B" << endl;
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t {0};
    cin >> t;
    while (t--) solve();
}
