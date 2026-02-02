#include <algorithm>
#include <iostream>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define range(i, a, b) for(i64 i = a; i < b; i++)

#define ar array
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

    ll t = 1;
    cin >> t;

    for (ll c = 0; c < t; c++) {
        ll a;
        cin >> a;
        ll b;
        cin >> b;
        ll x;
        cin >> x;
        ll y;
        cin >> y;

        dbg(a, b, x, y);

        ll w_max = max(x, a - x - 1);
        dbg(w_max * b);

        ll h_max = max(y, b - y - 1);
        dbg(h_max * a);

        ll area = max(w_max * b, h_max * a);
        cout << area << endl;
    }
}
