#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
#define int long long

signed main() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        arr[i] = x;
        x = (a * x + b) % c;
    }

    deque<int> d;
    int res = 0;

    for(int i = 0; i < n; ++i) {
        while(!d.empty() && d.front() <= i - k)
            d.pop_front();

        // remove element that are bigger
        while(!d.empty() && arr[d.back()] >= arr[i])
            d.pop_back();

        d.push_back(i);

        if(i >= k - 1) {
            res ^= arr[d.front()];
        }
    }

    cout << res << endl;
}