#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
using namespace std;

#define int long long int
#define endl "\n"
const int MOD = 1e9 + 7;
const int INF = 1e18;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#else
#define dbg(...)
#endif

int input() { int num; cin >> num; return num; }
#define fori(n) for (int i = 0; i < n; ++i)
#define forj(n) for (int j = 0; j < n; ++j)

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif

	int n = input();
	int a = input();
	int b = input();

	vector<vector<double>>dp(n + 1, vector<double>(6 * n + 1));

	dp[0][0] = 1;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6 * n; ++j) {
			for (int k = 1; k <= 6; ++k) {
				dp[i + 1][j + k] += dp[i][j] * (1.0 / 6.0);
			}
		}
	}

	
	dbg(dp[n])
	dbg(n, a, b)
	
	double sum = 0;
	
	for (int i = a; i <= b; ++i) {
		sum += dp[n][i];
	}
	
	cout << fixed << setprecision(6) << sum << endl;
}
