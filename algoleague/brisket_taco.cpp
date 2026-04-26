#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> vx(n);
    vector<int> vy(n);

    for(int i = 0; i < n; ++i) {
        cin >> vx[i] >> vy[i];
    }

    unordered_map<int, int> mm;

    for(int i = 0; i < n; ++i) {
        int val = vx[i] * m - vy[i];
        mm[val] += 1;
    }

    int res = 0;

    for(auto [num, count] : mm) {
        if(count > 1) {
            res += count * (count - 1) / 2;
        }
    }

    cout << res << endl;
}