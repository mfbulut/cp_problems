#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long int
const int MOD = 1e9 + 7;

#define fori(a, b) for(int i = (a); i < (b); ++i)
#define forj(a, b) for(int j = (a); j < (b); ++j)
#define fork(a, b) for(int k = (a); k < (b); ++k)

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;

    vector<string> input(n);
    fori(0, n) cin >> input[i];

    vector<vector<int>> dp(n, vector<int>(n));
    if(input[0][0] != '*') dp[0][0] = 1;

    fori(0, n) {
        forj(0, n) {
            if(input[i][j] == '*') {
                continue;
            }

            if(i - 1 >= 0 && input[i - 1][j] == '.') {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }

            if(j - 1 >= 0 && input[i][j - 1] == '.') {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}