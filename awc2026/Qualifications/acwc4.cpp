#include <algorithm>
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

ll v(ll num) {
    return num < 0 ? num : 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

    ll n = 1;
    cin >> n;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++) {
        ll num = 1;
        cin >> num;
        arr[i] = num;
    }

    dbg(arr);

    ll total = 0;

    for (ll i = 2; i < n; i++) {
        ll current = arr[i - 2] + arr[i - 1] + arr[i];

        if(current < 0){
            arr[i] -= current;
            total -= current;
        }
    }

    cout << total;
}
