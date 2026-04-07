#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    map<int, int> m;
    m[0] = 1;

    int num = 0;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num;
        count += m[sum - x];
        m[sum] += 1;
    }

    cout << count << endl;
}