// https://codeforces.com/contest/161/problem/D
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl '\n'
#define int long long
const int N = 1e6 + 1;
const int MOD = 911;
int k;
int total = 0;
void dfs(vector<vector<int>> &adj, vector<vector<int>> &dp, int cur, int par) {
    dp[cur][0] = 1;
    for (auto nei : adj[cur]) {
        if (nei == par)
            continue;
        // subtree hesaplansın
        dfs(adj, dp, nei, cur);
        // şuanki komşu (nei) subtree'sinde (k - i - 1) derinlikte,
        // önceki komşuların subtreelerinde i derinlikte olan nodeların sayısını
        // çarp cur'dan geçen pathlerden k uzunluğunda olanların sayısını bul
        for (int i = 0; i < k; i++) {
            total += dp[cur][i] * dp[nei][k - i - 1];
        }
        // 'önceki subtreeler' olarak kaydet
        for (int i = 0; i < k; i++) {
            dp[cur][i + 1] += dp[nei][i];
        }
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dfs(adj, dp, 1, -1);
    cout << total << endl;
}