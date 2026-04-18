#include <iostream>
#include <vector>

using namespace std;
#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }

const int mod = 1e9+7;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1));

    if(arr[0]) {
        dp[0][arr[0]] = 1;
    } else {
        for(int j = 1; j <= m; ++j) {
            dp[0][j] = 1;
        }
    }

    for(int i = 1; i < n; ++i) {
        int x = arr[i];

        if(x) {
            dp[i][x] += dp[i-1][x];
            dp[i][x] %= mod;

            if(x > 0) {
                dp[i][x] += dp[i-1][x-1];
                dp[i][x] %= mod;
            }

            if(x < m) {
                dp[i][x] += dp[i-1][x+1];
                dp[i][x] %= mod;
            }

        } else {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;

                if(j > 0) {
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= mod;
                }

                if(j < m) {
                    dp[i][j] += dp[i-1][j+1];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    if(arr[n - 1]) {
        cout << dp[n - 1][arr[n - 1]];
    } else {
        int sum = 0;

        for(int j = 1; j <= m; ++j) {
            sum += dp[n-1][j];
            sum %= mod;
        }

        cout << sum;
    }
}