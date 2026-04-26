#include <iostream>
#include <vector>

using namespace std;
#define int long long

int w, h;
int cnt = 0;
vector<vector<int>> m;

void dfs(int x, int y, bool first) {
    if (m[y][x]) return;

    m[y][x] = 2;

    if (first) cnt++;

    if (x > 0)     dfs(x - 1, y, false);
    if (x + 1 < w) dfs(x + 1, y, false);

    if (y > 0)     dfs(x, y - 1, false);
    if (y + 1 < h) dfs(x, y + 1, false);
}

signed main() {
    cin >> h >> w;

    m = vector<vector<int>>(h, vector<int>(w));

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            char c;
            cin >> c;
            m[y][x] = (c == '#');
        }
    }

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            dfs(x, y, true);
        }
    }

    cout << cnt;
}