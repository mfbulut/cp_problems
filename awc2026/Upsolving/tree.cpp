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

int n;
int total = 0;
vector<vector<int>> adj;
vector<int> dp;

void dfs(int cur, int par) {
    dp[cur] = 1;
    
    for (int nei : adj[cur]) {
        if (nei == par) continue;
        dfs(nei, cur);
        dp[cur] += dp[nei];
    }
}


signed main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif

	n = input(); 
	adj = vector<vector<int>>(n);
	dp = vector<int>(n);

	fori(n - 1) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
        adj[b].push_back(a);
	}

	dfs(0, -1);

	dbg(dp)

	cout << total << endl;
}
