#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define int long long int
#define ld long double

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

vector<int> values;
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int cur, int par) {
    for (auto nei : adj[cur]) {
        if (nei == par) continue;
        dfs(nei, cur);
        dp[cur][0] += max(dp[nei][0], dp[nei][1]);
    }

    for (auto nei : adj[cur]) {
        if (nei == par) continue;
        dp[cur][1] += dp[nei][0];
    }

    dp[cur][1] += values[cur];
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int n = input();

    values = vector<int>(n);
    adj = vector<vector<int>>(n);
    dp = vector<vector<int>>(n, vector<int>(2));

    fori(n - 1) {
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    fori(n) {
        values[i] = input();
    }

    dfs(0, -1);

    dbg(dp)

    cout << max(dp[0][0], dp[0][1]) << endl;
}
