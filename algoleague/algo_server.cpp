#include <iostream>
#include <vector>

using namespace std;
#define int long long

#pragma GCC optimize("O3")

const int max_sum = 5 * 1e5 + 5;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    k = min(max_sum, k);

    vector<int> arr;
    arr.reserve(n);

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        arr.push_back(x);
    }

    vector<bool> dp(k + 1);
    dp[0] = 1;

    for(int &j : arr) {
        for(int i = k; i >= 0; --i) {
            if(i + j <= k) {
                if(dp[i])
                    dp[i + j] = true;
            }
        }
    }

    for(int i = k; i >= 0; --i) {
        if(dp[i]) {
            cout << i << endl;
            break;
        }
    }
}