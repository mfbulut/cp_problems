#include <iostream>
#include <vector>
using namespace std;

#define int long long int
int MAX_N = 1e5 + 5;
int MOD = 1e9 + 7;
int INF = 1e9;

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
	vector<vector<int>> input(n, vector<int>(n)); 
	vector<int> dp(1 << n);

	fori(n) { 
		forj(n) { 
			cin >> input[i][j]; 
		}  
	} 


	for (int i = 0; i < (1 << n); ++i) {
	    int bit_count = __builtin_popcount(i);
	    for (int j = 0; j < n; ++j) {
	        if (((i >> j) & 1) == 0) {
	            dp[i | (1 << j)] =  max(dp[i | (1 << j)], dp[i] + input[bit_count][j]);
	        }
	    }
	}
	
	dbg(dp)

	cout << dp[(1 << n) - 1] << endl;
}
