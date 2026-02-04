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

    ll n; cin >> n;
    vector<ll> a(n + 2);
    vector<ll> b(n + 2);

    fori(0, n) cin >> a[i];
    fori(0, n) cin >> b[i];

    dbg(a, b);

    int res = 0;

    fori(0, n) {
        ll t1 = a[i] + b[i + 1] + b[i + 2];
        ll t2 = a[i] + a[i + 1] + a[i + 2];

        ll t3 = b[i] + b[i + 1] + a[i + 2];
        ll t4 = b[i] + b[i + 1] + b[i + 2];

        if(max(t1, t2) > max(t3, t4)) {
            res += a[i];
        } else {
            res += b[i];
        }
    }

    cout << res << "\n";
}