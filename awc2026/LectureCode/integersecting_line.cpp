#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
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

	int size_y = input();
	int size_x = input(); 

	int x1 = input();
	int y1 = input();
	
	int x2 = input(); 
	int y2 = input(); 

	int l1_x = x2 - x1;
	int l1_y = y2 - y1;
	
	forj(size_y) {
		fori(size_x) {
			int real_j = (size_y - j - 1);
			
			if(i < min(x1, x2) || real_j < min(y1, y2) || i > max(x1, x2) || real_j > max(y1, y2)) {
				cout << ".";
				continue;
			}
				
			int l2_x = i - x1;
			int l2_y = real_j - y1;

			int cross = l1_x * l2_y - l1_y * l2_x;
			
			if(cross) {
				cout << ".";
			} else {
				cout << "#";
			}			
		}
		
		cout << endl;
	}
}
