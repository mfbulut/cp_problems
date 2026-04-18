#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;
#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }

const int mod = 1e9 + 7;

signed main() {
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int maxn = 1e6;
    vector<int> lpc(maxn+1,0);
    lpc[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        if (lpc[i] == 0) {
            lpc[i] = i;
            for (int j = i * i; j <= maxn; j+=i)
                if(lpc[j] == 0)
                    lpc[j] = i;
        }
    }

    vector<int> res(n, 1);
    for (int i = 0; i < n; i++) {
        int x = arr[i];

        map<int, int> m;

        while(x > 1) {
            int p = lpc[x];
            x /= p;
            m[p]++;
        }

        for(pair<int, int> x : m) {
            if(x.second % 2 == 1) {
                res[i] = (res[i] * x.first) % mod;
            }
        }
    }

    
    partial_sum(res.begin(), res.end(), res.begin(), [](int a, int b){ return (a + b) % mod; });

    while(t--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int sub = a > 0 ? res[a - 1] : 0;
        cout << (res[b] - sub + mod) % mod << endl;
    }
}