#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e6 + 1;
const int MOD = 911;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int W;
    cin >> W;

    int k;
    cin >> k;
    vector<pair<int, int>> items(k);
    for (auto &[wi, vi] : items)
        cin >> wi >> vi;

    vector<int> dp(W + 1);
    for (auto [wi, vi] : items) {
        for (int i = W; i >= 0; i--) {
            if (i - wi >= 0)
                dp[i] = max(dp[i], dp[i - wi] + vi);
        }
    }
    cout << dp[W] << endl;
}