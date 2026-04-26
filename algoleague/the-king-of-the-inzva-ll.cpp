#include <iostream>
#include <vector>

using namespace std;
#define int long long


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }


signed main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> dp(n + 1, 1);
    vector<int> res(n + 1, -1);

    for(int i = 2; i <= n; ++i) {
        dp[i] += 1;

        if(dp[i] >= k) {
            int j = i;

            while(j >= 0 && res[j] == -1) {
                res[j] = i;
                j--;
            }
        }

        int j = 2;
        while(i * j <= n) {
            dp[i * j] += 1;
            j++;
        }
    }

    cout << dp;

    while(q--) {
        int num;
        cin >> num;

        if(num >= n) {
            cout << -1 << endl;
            continue;
        }

        cout << res[num + 1] << endl;
    }
}