#include <iostream>
#include <vector>
#include <set>
#include <map>

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


class Tarjan {
public:
    Tarjan(int n) {
        init(n);
    }

    void addEdge(int u, int v, bool is_directed = false) {
        adj[u].push_back(v);
        if (!is_directed)
            adj[v].push_back(u); // Assuming an undirected graph
    }

    void run() {
        for (int i = 0; i < adj.size(); ++i) {
            if (node_idx[i] == -1) {
                dfs(i);
            }
        }
    }

    map < int, int > getArticulationPoints() {
        return art_points;
    }

    vector < pair < int, int > > getBridges() {
        return bridges;
    }

    bool isBridge(int u, int v) {
        return find(bridges.begin(), bridges.end(), make_pair(u, v)) != bridges.end() ||
               find(bridges.begin(), bridges.end(), make_pair(v, u)) != bridges.end();
    }

    vector < vector < int > > getComponents() {
        return comps;
    }

private:
    int timer;
    vector < vector < int > > adj, comps;
    vector < int > low_link, node_idx, comp_idx;
    vector < bool > in_stack;
    stack < int > stk;
    vector < pair < int, int > > bridges;
    map < int, int > art_points;

    void init(int n) {
        timer = 0;
        adj.assign(n + 5, vector < int > ());
        low_link.assign(n + 5, -1);
        node_idx.assign(n + 5, -1);
        comp_idx.assign(n + 5, -1);
        in_stack.assign(n + 5, false);
        comps.clear();
        while (!stk.empty()) stk.pop();
    }

    void dfs(int u, int parent = -1) {
        low_link[u] = node_idx[u] = timer++;
        in_stack[u] = true;
        stk.push(u);

        int childs = 0;

        for (int v : adj[u]) {
            if (v == parent) continue; // Ignore the edge to parent in undirected graph
            if (node_idx[v] == -1) { // If v is not visited
                dfs(v, u);
                low_link[u] = min(low_link[u], low_link[v]);
                if (low_link[v] == node_idx[v])
                    bridges.emplace_back(u, v);
                if (parent != -1 && low_link[v] >= node_idx[u])
                    art_points[u] += 1;
                ++childs;
            } else if (in_stack[v]) {
                low_link[u] = min(low_link[u], node_idx[v]);
            }
        }

        if (parent == -1 && childs > 1)
            art_points[u] += 1;

        if (low_link[u] == node_idx[u]) {
            comps.emplace_back();
            int v;
            do {
                v = stk.top();
                stk.pop();
                in_stack[v] = false;
                comps.back().push_back(v);
                comp_idx[v] = comps.size() - 1;
            } while (v != u);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("q7.in", "r", stdin);
#endif

    ll n = get();
    ll e = get();

    Tarjan t(n);

    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        t.addEdge(u, v);
    }

    t.run();

    dbg(t.getArticulationPoints())
}