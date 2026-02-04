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

int dp[1000007] = {0};

int solve(int n) {
    if(n == 0) return 0;
    if(dp[n] > 0) return dp[n];

    int m_max = 1e9;
    int new_n = n;

    while(new_n > 0) {
        int digit = new_n % 10;

        if(digit != 0) m_max = min(m_max, 1 + solve(n - digit));

        new_n /= 10;
    }

    dp[n] = m_max;
    return m_max;
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    cout << solve(n);
}