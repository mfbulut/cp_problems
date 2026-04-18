#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main() {
    int start, end;
    cin >> start >> end;
    int target = end - start;

    int t, n;
    cin >> t >> n;

    vector<int> arr(n);
    int res = 1e10;

    while(t--) {
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> dp(target + 1, 1e10);
        dp[0] = 0;

        for(int i = 0; i <= target; ++i) {
            for(int j : arr) {
                if(i + j <= target) {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }

        res = min(res, dp[target]);
    }

    if(res != 1e10)
        cout << res << endl;
    else
        cout << "-1" << endl;
}
