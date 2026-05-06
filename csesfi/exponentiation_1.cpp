#include <bits/stdc++.h>

using namespace std;
#define int long long

int modpow(int base, int exp, int mod) {
    base %= mod;
    long ans = 1;
    while (exp > 0) {
        if (exp & 1) ans = ans * base % mod;
        base = (long)base * base % mod;
        exp /= 2;
    }
    return ans;
}

signed main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        cout << modpow(a, b, 1e9+7) << endl;
    }
}