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

    string arr; cin >> arr;

    char last = -1;
    int count = -1;
    int max_count = -1;

    for(char c : arr) {
        if(c != last) {
            last = c;
            count = 1;
        } else {
            count++;
        }

        max_count = max(max_count, count);
    }

    cout << max_count;
}