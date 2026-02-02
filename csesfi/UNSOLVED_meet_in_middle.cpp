#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
using namespace std;

#pragma GCC optimize("O3")
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

	vector<int>arr(n);

	fori(n) {
		cin >> arr[i];
	}

	int result = 0;
	unordered_map<int, int>umap;

	int a = n / 2;
	int b = n - a;

	for (int i = 0; i < (1 << a); ++i) {
		int sum = 0;

		for (int j = 0; j < a; ++j) {
			if ((i >> j) & 1) {
				sum += arr[j];
			}
		}

		if(sum <= k)
			umap[sum] += 1;
	}

	for (int i = 0; i < (1 << b); ++i) {
		int sum = 0;

		for (int j = 0; j < b; ++j) {
			if ((i >> j) & 1) {
				sum += arr[a + j];
			}
		}

		if(sum <= k)
			result += umap[k - sum];
	}

	cout << result << endl;
}

