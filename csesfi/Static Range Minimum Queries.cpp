#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
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

    vector<ll> s_tree(n * 2, INF);

    fori(n) {
        cin >> s_tree[n + i];
    }"

    for (int i = n - 1; i > 0; --i) {
        s_tree[i] = min(s_tree[2 * i], s_tree[2 * i + 1]);
    }

    dbg(s_tree);

    fori(q) {
        ll l = input() - 1;
        ll r = input();

        ll res = INF;

        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, s_tree[l++]);
            if (r & 1) res = min(res, s_tree[--r]);
        }

        cout << res << "\n";
    }
}
