#include <iostream>
#include <vector>

// #include <unordered_map>
// #include <map>

// #include <unordered_set>
// #include <set>

// #include <iomanip>
// std::cout << std::fixed << std::setprecision(6) << f << '\n';

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll long long
#define ld long double

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll get() { ll n; cin >> n; return n; }
vector<ll> get_array(ll n) { vector<ll> arr(n); for(ll i = 0; i < n; ++i) { cin >> arr[i];} return arr; }
vector<vector<ll>> make2d(ll a, ll b) { return vector<vector<ll>>(a, vector<ll>(b)); }
#define range(i, a, b) for(ll i = a; i < b; ++i)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("q8.in", "r", stdin);
#endif

    ll n = get();
    auto arr = get_array(n);
    dbg(arr)

    vector<ll> inc_dp(n);
    vector<ll> dec_dp(n);

    range(i, 1, n) {
        if(arr[i] == arr[i - 1]) {
            inc_dp[i] = inc_dp[i - 1];
            dec_dp[i] = dec_dp[i - 1];
            continue;
        }

        bool a = false;
        bool b = false;
        for(int j = i - 1; j >= 0; --j) {
            if(arr[i] > arr[j]) {
                inc_dp[i] = max(inc_dp[i], dec_dp[j] + 1);
                a = true;
            } else if(arr[i] < arr[j]) {
                dec_dp[i] = max(dec_dp[i], inc_dp[j] + 1);
                b = true;
            }

            if(a && b) break;
        }
    }

    dbg(inc_dp)
    dbg(dec_dp)

    cout << max(inc_dp[n - 1], dec_dp[n - 1]) + 1 << endl;
}