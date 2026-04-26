#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> dp(1 << n, 1e18);
    dp[0] = 0;

	for (int i = 0; i < (1 << n); ++i) {
	    for (int j = 0; j < n; ++j) {
	        if (i & (1 << j)) continue;

            if(dp[i] % m + arr[j] > m) {
                dp[i | (1 << j)] = min(dp[i | (1 << j)], (dp[i] / m + 1) * m + arr[j]);
            } else {
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + arr[j]);
            }
	    }
	}


	cout << (dp[(1 << n) - 1] - 1) / m + 1;
}