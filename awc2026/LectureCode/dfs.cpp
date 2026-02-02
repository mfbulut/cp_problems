#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl '\n'
#define int long long
const int N = 1e6 + 1;
const int MOD = 911;

void dfs(vector<vector<int>> &adj, int cur, int par) {
    for (auto nei : adj[cur]) {
        if (nei != par)
            dfs(adj, nei, cur);
    }
    cout << "cur: " << cur << ", par: " << par << endl;
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
    dfs(adj, 1, -1);
}