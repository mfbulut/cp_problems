#include <iostream>
#include <vector>

using namespace std;
#define ll long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#else
#define dbg(...)
#endif

vector<vector<ll>> adj;
vector<ll> lis;
vector<ll> value;

int answer = 0;

void dfs(ll cur, ll par) {
    int x = value[cur];

    int pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
    int old = -1;

    if (pos == lis.size()) {
        lis.push_back(x);
    } else {
        old = lis[pos];
        lis[pos] = x;
    }

    answer = max(answer, (int)lis.size());

    for (auto nei : adj[cur]) {
        if (nei != par) dfs(nei, cur);
    }

    if (pos == lis.size() - 1 && old == -1)
        lis.pop_back();
    else
        lis[pos] = old;
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ll n; cin >> n;

    value = vector<ll>(n);
    adj = vector<vector<ll>>(n);

    for(ll i = 0; i < n - 1; ++i) {
        cin >> value[i + 1];
    }

    ll u, v;
    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    cout << answer << endl;
}

