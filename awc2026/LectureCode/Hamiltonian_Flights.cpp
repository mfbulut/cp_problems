#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[--u].push_back(--v);
    }
    // 0.node -> n - 1.node
    // ancak mask 0111111 ise son node'a gidilebilir (tüm nodelar 1 kere
    // gezilecek)
    int target = ((1 << (n - 1)) - 1);
    vector<vector<int>> dp(1 << n, vector<int>(n));
    dp[1][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        // 0. node(başlangıç) zaten ziyaret edilmiş olmalı
        if ((mask & 1) != 1)
            continue;
        // zaten ziyaret edilmiş her node için
        for (int node = 0; node < n; node++) {
            // ziyaret edilmemişse geç
            if ((mask & (1 << node)) == 0)
                continue;
            // bu node'un komşuları arasından
            for (auto nei : adj[node]) {
                // zaten ziyaret edilmişleri veya
                // son city'ye gidip daha tüm cityleri gezmemiş olanları geç
                if (((mask & (1 << nei))) || ((nei == n - 1) && mask != target))
                    continue;
                // gezdiğini belirten: mask | (1 << nei)
                // hangi node'da bittiğini belirten nei
                dp[mask | (1 << nei)][nei] =
                    (dp[mask | (1 << nei)][nei] + dp[mask][node]) % MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
}