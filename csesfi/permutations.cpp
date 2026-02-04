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

    if(n == 1) {
        cout << 1;
        return 0;
    }

    if(n == 2) {
        cout << "NO SOLUTION";
        return 0;
    }

    if(n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    if(n == 4) {
        cout << "2 4 1 3";
        return 0;
    }

    forj(1, n + 1) {
        if(j % 2 == 0) cout << j << " ";
    }

    forj(1, n + 1) {
        if(j % 2 == 1) cout << j << " ";
    }
}