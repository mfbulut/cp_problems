#include <iostream>
#include <unordered_map>
#include <vector>
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

vector<vector<int>> mult_mat(vector<vector<int>>& m1, vector<vector<int>>& m2) {
    int r1 = m1.size();
    int c1 = m1[0].size();
    int r2 = m2.size();
    int c2 = m2[0].size();

   	vector<vector<int>> res(r1, vector<int>(c2, 0));

    if (c1 != r2) {
        cout << "Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
               	res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % MOD;

            }
        }
    }

    return res;
}

vector<vector<int>> fast_pow(vector<vector<int>>& mat, int n) {
	if(n == 0) {
	    vector<vector<int>> imat = {{1, 0}, {
	                                 0, 1}};
	    return imat;
	}

	vector<vector<int>> res = fast_pow(mat, n / 2);
	res = mult_mat(res, res);

	if(n & 1) {
		res = mult_mat(res, mat);
	}

	return res;
}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif

	int n = input();

   	vector<vector<int>> mat = {{1, 1}, {1, 0}};
	mat = fast_pow(mat, n);
    //                          f(1)  f(0)
   	vector<vector<int>> start = {{0}, {1}};
	mat = mult_mat(mat, start);

	cout << mat[0][0] << endl;
}
