#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl '\n'
#define int long long
const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins)
        cin >> c;
    vector<int> dp(x + 1);

    dp[0] = 1;
    // sadece alttaki iki satırın yer değiştirmesi ordered/unordered yapıyor
    for (auto &c : coins) {
        for (int i = 0; i < x; i++) {
            if (i + c <= x)
                dp[i + c] = (dp[i + c] + dp[i]) % MOD;
        }
    }
    cout << dp[x] << endl;
}