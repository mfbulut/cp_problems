#include <bits/stdc++.h>
using namespace std;

int main() {
    // https://oeis.org/A036685
    set<int> s = {0, 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222};

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (s.count(n) ? "second" : "first") << "\n";
    }
}