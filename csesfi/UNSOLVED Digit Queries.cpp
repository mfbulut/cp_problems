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

    vector<ll> arr(n);

    fori(0, n) {
        cin >> arr[i];
    }

    fori(0, n) {
        dbg(i, arr);
    }
}