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

ll n;
vector<ll> arr;

void build() {
    for (ll i = n - 1; i > 0; --i) arr[i] = min(arr[i * 2], arr[i * 2 | 1]);
}

void modify(ll p, ll value) {
    for (arr[p += n] = value; p > 1; p /= 2) arr[p / 2] = min(arr[p], arr[p^1]);
}

// [l, r)
ll query(ll l, ll r) {
    ll res = 1e9;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = min(res, arr[l++]);
        if (r & 1) res = min(res, arr[--r]);
    }
    return res;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    ll t; cin >> t;
    arr = vector<ll>(2 * n);

    fori(0, n) cin >> arr[n + i];
    build();

    ll op, a, b;
    while(t--) {
        cin >> op >> a >> b;

        if(op == 1) {
            modify(a - 1, b);
        } else {
            cout << query(a - 1, b) << "\n";
        }
    }
}