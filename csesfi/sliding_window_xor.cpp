#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    int res_xor = 0;
    int sum = 0;

    vector<int> arr(n);

    for(int i = 0; i < k; ++i) {
        arr[i] = x;
        sum ^= x;
        x = (a * x + b) % c;
    }

    res_xor ^= sum;

    for(int i = k; i < n; ++i) {
        arr[i] = x;
        sum ^= x;
        sum ^= arr[i-k];
        x = (a * x + b) % c;
        res_xor ^= sum;
    }

    cout << res_xor << endl;
}