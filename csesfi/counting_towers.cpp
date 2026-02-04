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
const int MAX_N = 1000001;

#define fori(a, b) for(int i = (a); i < (b); ++i)
#define forj(a, b) for(int j = (a); j < (b); ++j)
#define fork(a, b) for(int k = (a); k < (b); ++k)

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int t; cin >> t;
    vector<int> dp_1(MAX_N);
    vector<int> dp_2(MAX_N);

    dp_1[1] = 1;
    dp_2[1] = 1;

    fori(2, MAX_N) {
        int last_flat  = dp_1[i - 1];
        int last_split = dp_2[i - 1];

        dp_1[i] = (dp_1[i] + ((2 * last_flat) % MOD + (1 * last_split) % MOD) % MOD) % MOD;
        dp_2[i] = (dp_2[i] + ((1 * last_flat) % MOD + (4 * last_split) % MOD) % MOD) % MOD;
    }

    while(t--) {
        int n; cin >> n;
        cout << (dp_1[n] + dp_2[n]) % MOD << endl;
    }
}