#include <iostream>
#include <vector>
#include <algorithm>
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
    int x, y; 
    cin >> x >> y;

    vector<int> arr1(x);
    fori(0, x) cin >> arr1[i];
    
    vector<int> arr2(y);
    fori(0, y) cin >> arr2[i];

    vector<vector<int>> dp(x + 1, vector<int>(y + 1));

    for (int j = 1; j <= y; ++j) {
        for (int i = 1; i <= x; ++i) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[x][y] << endl;
    
    int i = x, j = y;
    vector<int> lcs;
    
    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            lcs.push_back(arr1[i - 1]);
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } 
        else {
            j--;
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    
    for (int v : lcs) {
        cout << v << " ";
    }
    cout << endl;

}
