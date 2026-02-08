#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<int> arr(n);

	fori(n) {
		cin >> arr[i];
	}

	long double res = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int sum = 0;

			int a = arr[i];
			int b = arr[j];

			for(int k = 1; k <= b; ++k)
				sum += max(0LL, a - k);

			res += (long double)sum / (long double)(a * b);
		}
	}

	cout << fixed << setprecision(6) << res << endl;
}
