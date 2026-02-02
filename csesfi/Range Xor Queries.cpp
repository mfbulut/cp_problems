#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#ifdef LOCAL
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
#define dbg(x) cerr << #x << ": " << x << '\n';
#else
#define dbg(...)
#endif

ll input() { ll num; cin >> num; return num; }
#define fori(n) for (ll i = 0; i < n; ++i)
#define forj(n) for (ll j = 0; j < n; ++j)

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif

    ll n = input();
    ll q = input();

    vector<ll> arr(n);

    fori(n) {
        cin >> arr[i];
    }

    vector<ll> prefix_xor(n + 1);

    ll res = 0;
    fori(n) {
        res ^= arr[i];
        prefix_xor[i + 1] = res;
    }

    dbg(arr)
    dbg(prefix_xor)

    fori(q) {
        ll start = input();
        ll end = input();
        cout << (prefix_xor[end] ^ prefix_xor[start - 1]) << endl;
    }
}
