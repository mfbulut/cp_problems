#include <iostream>
#include <vector>
#include <array>

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

std::array<ll, 3> vec_sub(const std::array<ll, 3> &A, const std::array<ll, 3> &B) {
    std::array<ll, 3> product;
    product[0] = A[0] - B[0];
    product[1] = A[1] - B[1];
    product[2] = A[2] - B[2];
    return product;
}

std::array<ll, 3> vec_cross(const std::array<ll, 3> &A, const std::array<ll, 3> &B) {
    std::array<ll, 3> product;
    product[0] = (A[1] * B[2]) - (A[2] * B[1]);
    product[1] = -((A[0] * B[2]) - (A[2] * B[0]));
    product[2] = (A[0] * B[1]) - (A[1] * B[0]);
    return product;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("q2.in", "r", stdin);
#endif

    ll t = get();

    while(t--) {
        std::array<ll, 3> p1 = { get(), get(), get() };
        std::array<ll, 3> p2 = { get(), get(), get() };
        std::array<ll, 3> p3 = { get(), get(), get() };
        std::array<ll, 3> p4 = { get(), get(), get() };

        auto p1_to_p2 = vec_sub(p2, p1);
        auto p2_to_p3 = vec_sub(p3, p2);
        auto p2_to_p4 = vec_sub(p4, p2);

        std::array<ll, 3> cross1 = vec_cross(p1_to_p2, p2_to_p3);
        std::array<ll, 3> cross2 = vec_cross(p1_to_p2, p2_to_p4);

        std::array<ll, 3> cross3 = vec_cross(cross1, cross2);

        if(cross3[0] == 0 && cross3[1] == 0 && cross3[2] == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}