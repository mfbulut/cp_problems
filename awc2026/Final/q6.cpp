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

#define add_mod(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define sub_mod(a, b) (((a % MOD) - (b % MOD) + m) % MOD)
#define mul_mod(a, b) (((a % MOD) * (b % MOD)) % MOD)

vector<vector<ll>> mult_mat(vector<vector<ll>>& m1, vector<vector<ll>>& m2) {
    ll r1 = m1.size();
    ll c1 = m1[0].size();
    ll r2 = m2.size();
    ll c2 = m2[0].size();

   	vector<vector<ll>> res(r1, vector<ll>(c2, 0));

    if (c1 != r2) {
        cout << "Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }

    for (ll i = 0; i < r1; i++) {
        for (ll j = 0; j < c2; j++) {
            for (ll k = 0; k < c1; k++) {
               	res[i][j] = add_mod(res[i][j], mul_mod(m1[i][k], m2[k][j]));
            }
        }
    }

    return res;
}

vector<vector<ll>> imat;

vector<vector<ll>> fast_pow(vector<vector<ll>>& mat, ll n) {
	if(n == 0) {
	    return imat;
	}

	vector<vector<ll>> res = fast_pow(mat, n / 2);
	res = mult_mat(res, res);

	if(n & 1) {
		res = mult_mat(res, mat);
	}

	return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("q6.in", "r", stdin);
#endif

    ll n = get();

    if(n == 0) {
        cout << 0 << endl;
        return 0;
    } else if(n == 1) {
        cout << 0 << endl;
        return 1;
    }

	// Idenity matrix
   	imat = vector<vector<ll>>(2, vector<ll>(2));
   	range(i, 0, 2) imat[i][i] = 1;

   	vector<vector<ll>> mat = {
   		{2, 1},
   		{0, 3},
   	};

	mat = fast_pow(mat, n - 1);

   	vector<vector<ll>> start = {{1}, {3}};
	mat = mult_mat(mat, start);

    cout << mat[0][0] << endl;
}