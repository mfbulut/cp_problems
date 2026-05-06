#include <bits/stdc++.h>

using namespace std;
#define int long long

// https://cses.fi/problemset/task/1662/

signed main() {
    int n;
    cin >> n;

    // prefix sum

    vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    partial_sum(arr.begin(), arr.end(), arr.begin());

    // Count

    int count = 0;
    map<int, int> m;
    m[0] = 1;

    for (int num : arr) {
        num = (n + (num % n)) % n;
        count += m[num];
        m[num] += 1;
    }

    cout << count << endl;
}