#include <bits/stdc++.h>
using namespace std;

#define int long long

string encode(const vector<int>& v) {
    string s;
    for (int x : v) s += char(x + '0');
    return s;
}

signed main() {
    vector<int> v(9);
    vector<int> target = {0,1,2,3,4,5,6,7,8};

    for (int i = 0; i < 9; ++i) cin >> v[i];

    queue<pair<vector<int>, int>> q;
    unordered_set<string> vis;

    q.push({v, 0});
    vis.insert(encode(v));

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == target) {
            cout << dist;
            return 0;
        }

        int pos = find(node.begin(), node.end(), 0) - node.begin();
        int x = pos / 3, y = pos % 3;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                int new_pos = nx * 3 + ny;

                vector<int> next = node;
                swap(next[pos], next[new_pos]);

                string code = encode(next);
                if (!vis.count(code)) {
                    vis.insert(code);
                    q.push({next, dist + 1});
                }
            }
        }
    }
}