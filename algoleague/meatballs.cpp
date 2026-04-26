#include <iostream>
#include <vector>
using namespace std;

#define int long long int

signed main() {
	int n;
	cin >> n;

	vector<vector<int>> input(n, vector<int>(n));
	vector<int> dp(1 << n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input[i][j];
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
	    int bit_count = __builtin_popcount(i);

	    for (int j = 0; j < n; ++j) {
	        if ((1 << j) & i) continue;

            dp[i | (1 << j)] =  max(dp[i | (1 << j)], dp[i] + input[bit_count][j]);

	    }
	}

	cout << dp[(1 << n) - 1] << endl;
}