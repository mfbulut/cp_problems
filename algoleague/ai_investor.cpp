#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;

#define fori(n) for (int i = 0; i < (n); ++i)
#define forj(n) for (int j = 0; j < (n); ++j)
#define fork(n) for (int k = 0; k < (n); ++k)

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    vector<int> nums(n);
    vector<int> indexed(n);
    fori(n) cin >> nums[i];
    fori(n) indexed[i] = i;
    sort(indexed.begin(), indexed.end(), [&](int i, int j) { return nums[i] < nums[j]; });

    vector<bool> dp(n);

    int total = 0;
    int count = 1;

    fori(n) {
        int cur = indexed[i];
        int next = cur + 1;
        int prev = cur - 1;

        if(next < n  && !dp[next]) count += 1;
        if(prev >= 0 && !dp[prev]) count += 1;

        total += (count - 1);

        if(next < n  && dp[next]) count -= 1;
        if(prev >= 0 && dp[prev]) count -= 1;

        dp[cur] = true;
    }

    cout << total << endl;
}


// nums: 6 5 2 3 7 1 4
// indexed: 5,2,3,6,1,0,4

// counts: 3,4,4,5,2,2,4
// indexed counts: 2,4,5,4,4,3,2

//                     -----  +  -
// set: {5}            01234 (5) 6

//                     --  +  -- + -
// set: {2,5}          01 (2) 34 5 6

//                     -- +  +  - + -
// set: {2,3,5}        01 2 (3) 4 5 6

//                     -- ++ - +  +
// set: {2,3,5,6}      01 23 4 5 (6)

//                     -  +  ++ - ++
// set: {1,2,3,5,6}    0 (1) 23 4 56

//                      +  +++ - ++
// set: {0,1,2,3,5,6}  (0) 123 4 56

//                     ++++  +  ++
// set: {0,1,2,3,5,6}  0123 (4) 56
