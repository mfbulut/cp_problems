#include <iostream>
#include <vector>

using namespace std;
#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }

signed main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));

    for(int y = 0; y < n; ++y) {
        for(int x = 0; x < n; ++x) {
            char c;
            cin >> c;

            if(c == '*') {
                arr[x][y] = 1;
            }
        }
    }

    for(int y = 0; y < n; ++y) {
        for(int x = 0; x < n; ++x) {
            int sum = arr[x][y];

            if(x > 0) {
                sum += dp[x - 1][y];
            }

            if(y > 0) {
                sum += dp[x][y - 1];
            }

            if(x > 0 && y > 0) {
                sum -= dp[x - 1][y - 1];
            }

            dp[x][y] = sum;
        }
    }

    int y1, x1, y2, x2;

    while(q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;

        int ans = dp[x2][y2];

        if (x1 > 0) ans -= dp[x1 - 1][y2];
        if (y1 > 0) ans -= dp[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) ans += dp[x1 - 1][y1 - 1];

        cout << ans << endl;
    }

}