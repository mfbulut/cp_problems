#include <cstdlib>
#include <iostream>
#include <vector>

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

    ll n;
    cin >> n;

    ll k;
    cin >> k;

    vector<ll> a_arr(n);
    vector<ll> b_arr(n);

    for (ll i = 0; i < n; i++) {
        cin >> a_arr[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> b_arr[i];
    }

    dbg(a_arr);
    dbg(b_arr);

    ll total = 0;
    ll a_sum = 0;
    ll b_sum = 0;

    bool is_on_a = true;
    for (ll i = 0; i < n; i++) {
        a_sum += a_arr[i];
        b_sum += b_arr[i];

        if (is_on_a) {
            if (a_sum - b_sum > k) {
                dbg(a_sum);
                dbg(b_sum);
            } else {

            }
        } else {

        }

    }

    dbg(total);
}
