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

    int t; cin >> t;

    while(t--) {
        string s; cin >> s;
        int n = 1; fori(0, s.size()) n *= 2; n -= 1;
        int x; cin >> x;

        int i = 0;
        int mid = n / 2 + 1;
        int res = 1;

        while (x != mid) {
            if(x > mid) {
                if(s[i] == 'R') {
                    x -= mid;
                } else {
                    x = mid - (x - mid);
                    res *= -1;
                }
            } else {
                if(s[i] == 'R') {
                    x = mid - x;
                    res *= -1;
                } else {
                    // Nothing
                }
            }

            i++;
            n /= 2;
            mid = n / 2 + 1;
        }

        if(res == 1) {
            cout << "D" << "\n";
        } else {
            cout << "U" << "\n";
        }
    }
}
