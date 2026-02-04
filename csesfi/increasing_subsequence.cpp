#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#ifdef LOCAL
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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

    vector<ll> arr(n);
    vector<ll> dp(n, 1);

    fori(n) {
        cin >> arr[i];
    }

    vector<long long> lis;

    for (ll x : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            // Overrite since we are only conserned about the lenght
            *it = x;
        }
    }

    dbg(arr)
    dbg(lis)
    
    cout << lis.size();
}