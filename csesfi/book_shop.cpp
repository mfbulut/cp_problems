#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long int
#define fori(a, b) for(int i = (a); i < (b); ++i)
#define forj(a, b) for(int j = (a); j < (b); ++j)
#define fork(a, b) for(int k = (a); k < (b); ++k)

signed main() {
    int n, x; 
    cin >> n >> x;

    vector<int> price(n);
    fori(0, n) cin >> price[i];
    
    vector<int> value(n);
    fori(0, n) cin >> value[i];

    vector<int> dp(x + 1);
         
    for (int i = 0; i < n; i++)
      for (int j = x; j >= price[i]; j--)
        dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
    
    
    fori(0, n) {
        dbg(dp)
    }
    
    cout << dp[x] << endl;
}
