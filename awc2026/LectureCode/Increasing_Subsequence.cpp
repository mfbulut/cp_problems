#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <tuple>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl '\n'
#define int long long
mt19937_64
    rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define debug(...) 4
#endif

const int N = 1e6 + 1;
const int MOD = 911;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#if defined(LOCAL) && !defined(ONLINE_JUDGE) && defined(FILE_INPUT)
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> tail;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        int idx = lower_bound(tail.begin(), tail.end(), cur) - tail.begin();
        if (idx == tail.size()) {
            tail.push_back(cur);
        } else {
            tail[idx] = cur;
        }
    }
    debug(tail);
    cout << tail.size() << endl;
}