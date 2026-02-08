#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long int
#define fori(a, b) for(int i = (a); i < (b); ++i)
#define forj(a, b) for(int j = (a); j < (b); ++j)
#define fork(a, b) for(int k = (a); k < (b); ++k)

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;

    vector<int> arr(n);
    fori(0, n) cin >> arr[i];

    fori(0, n) {
        dbg(i, arr[i]);
    }
}