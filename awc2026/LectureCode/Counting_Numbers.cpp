#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl '\n'
#define int long long
const int N = 1e6 + 1;
const int MOD = 911;
int count(vector<int> &num, int pos, bool smaller, bool started) {
    int ans = 0;
    if (pos == num.size())
        return 1LL;
    if (smaller) {
        if (!started) {
            ans += 9 * count(num, pos + 1, true, true);
            ans += count(num, pos + 1, true, false);
        } else {
            ans += 9 * count(num, pos + 1, true, true);
        }
    } else {
        assert(started);
        // eşit
        if (num[pos - 1] != num[pos])
            ans += count(num, pos + 1, false, true);
        if ((num[pos] - (num[pos - 1] < num[pos])) > 0)
            ans += (num[pos] - (num[pos - 1] < num[pos])) *
                   count(num, pos + 1, true, true);
    }
    return ans;
}

int solve(int x) {
    if (x < 10) {
        return x + 1;
    }
    vector<int> num;
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    int ans = 0;
    ans += count(num, 1, false, true);
    for (int i = 1; i < num[0]; i++) {
        ans += count(num, 1, true, true);
    }
    // #
    ans += count(num, 1, true, false);
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
}