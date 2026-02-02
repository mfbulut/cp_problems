#include <iostream>
#include <vector>
using namespace std;

#define int long long int
#define endl "\n"
const int MOD = 1e9 + 7;
const int INF = 1e18;

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
	vector<int>arr(n);

	fori(n) {
		cin >> arr[i];
	}

	dbg(arr)

	fori(1 << n) {
		int sum = 0;
		
		forj(n) {
			if((i >> j) & 1) {
				sum += arr[j];
			} else {
				sum -= arr[j];
			}
		}

		dbg(sum)
		
		if(sum % 360 == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}
