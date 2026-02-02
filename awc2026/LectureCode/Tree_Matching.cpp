#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl '\n'
#define int long long
const int N = 1e6 + 1;
const int MOD = 911;
void dfs(vector<vector<int>> &adj, vector<array<int, 2>> &dp, int cur,
         int par) {
    int mini = INT64_MAX;
    for (auto nei : adj[cur]) {
        if (nei == par)
            continue;
        dfs(adj, dp, nei, cur);
        // herhangi bir [cur, nei] seçilmeden
        dp[cur][0] += max(dp[nei][0], dp[nei][1]);
    }
    for (auto nei : adj[cur]) {
        if (nei == par)
            continue;
        // bir tane [cur, nei] seçilirse
        dp[cur][1] = max(dp[cur][1], dp[cur][0] - max(dp[nei][0], dp[nei][1]) +
                                         dp[nei][0] + 1);
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<int, 2>> dp(n + 1);
    dfs(adj, dp, 1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}