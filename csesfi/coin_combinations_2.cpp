#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long int
const int mod = 1e9 + 7;
#define fori(a, b) for(int i = (a); i < (b); ++i)
#define forj(a, b) for(int j = (a); j < (b); ++j)
#define fork(a, b) for(int k = (a); k < (b); ++k)

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    int x; cin >> x;

    vector<int> coins(n);
    fori(0, n) cin >> coins[i];

    vector<int> arr(x + 1);
    arr[0] = 1;

    for (int coin : coins) {
        fori(1, x + 1) {
            if (i - coin >= 0) {
                arr[i] = (arr[i] + arr[i - coin]) % mod;
            }
        }
    }

    cout << arr[x];
}