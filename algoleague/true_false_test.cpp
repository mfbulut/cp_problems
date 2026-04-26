#include <iostream>
#include <vector>

using namespace std;
#define int long long

const int mod = 1e9+7;

signed main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(8));
    dp[1][0] = 1;
    dp[1][4] = 1;

    // dp[i][0] F
    // dp[i][1] FF
    // dp[i][2] FFF
    // dp[i][3] FFFF

    // dp[i][4] T
    // dp[i][5] TT
    // dp[i][6] TTT
    // dp[i][7] TTTT

    for(int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][4] + dp[i-1][5] + dp[i-1][6] + dp[i-1][7];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
        dp[i][3] = dp[i-1][2];

        dp[i][4] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
        dp[i][5] = dp[i-1][4];
        dp[i][6] = dp[i-1][5];
        dp[i][7] = dp[i-1][6];

        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i][2] %= mod;
        dp[i][3] %= mod;
        dp[i][4] %= mod;
        dp[i][5] %= mod;
        dp[i][6] %= mod;
        dp[i][7] %= mod;
    }

    int total = 0;

    for(int e : dp[n]) {
        total += e;
    }

    int all = 1;
    for(int i = 1; i <= n; ++i) {
        all *= 2;
        all %= mod;
    }

    cout << (((all - total) % mod + mod) % mod);
}
