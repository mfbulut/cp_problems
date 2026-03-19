#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int longest_path = 0;

int dfs(int node) {
    int left_len = 0, right_len = 0;

    if (adj[node].size() >= 1) {
        left_len = dfs(adj[node][0]) + 1;
    }

    if (adj[node].size() >= 2) {
        right_len = dfs(adj[node][1]) + 1;
    }

    longest_path = max(longest_path, left_len + right_len);

    return max(left_len, right_len);
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);

    int u, d, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> d >> v;
        adj[--u].push_back(--v);
    }

    dfs(0);

    cout << longest_path;
}