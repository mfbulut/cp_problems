#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = a[0], sum = 0, min_sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }

    cout << ans;
}