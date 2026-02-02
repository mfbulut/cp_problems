#include <iostream>
#include <vector>
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
	int k = input();

	vector<int> nimbers(n + 1);
	vector<int> moves(k);
	
	fori(k) {
		cin >> moves[i];
	}

	for (int i = 1; i <= n; i++) {
	    vector<bool> seen(k + 1);

	    for (int mv : moves) {
	        if (i - mv >= 0) {
	            int g = nimbers[i - mv];
	            seen[g] = true;
	        }
	    }

	    for (int j = 0; j <= k; j++) {
	        if (!seen[j]) {
	            nimbers[i] = j;
	            break;
	        }
	    }
	}
	
	dbg(nimbers)

	for (int i = 1; i <= n; i++) {
		if(nimbers[i] != 0) {
			cout << "W";
		} else {
			cout << "L";
		}
	}
	
	cout << endl;
}
