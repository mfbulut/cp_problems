#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define ll long long int
#define fori(a, b) for(ll i = (a); i < (b); ++i)
#define forj(a, b) for(ll j = (a); j < (b); ++j)
#define fork(a, b) for(ll k = (a); k < (b); ++k)

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int t; cin >> t;

	while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        fori(0, n) cin >> arr[i];

        int res = 0;
        fori(0, n) res ^= arr[i];

        if(res) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
    }
}