#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

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

ld input() { ld num; cin >> num; return num; }
#define fori(n) for (int i = 0; i < n; ++i)
#define forj(n) for (int j = 0; j < n; ++j)

#define PI 3.14159265358979323846

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ld x1 = input();
    ld y1 = input();
    ld r1 = input();

    ld x2 = input();
    ld y2 = input();
    ld r2 = input();

    ld area_1 = PI * r1 * r1;
    ld area_2 = PI * r2 * r2;

    ld dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (dist >= r1 + r2) {
        cout << fixed << setprecision(2) << area_1 + area_2 << endl;
        return 0;
    }

    if(dist <= abs(r1 - r2)) {
        cout << fixed << setprecision(2) << max(area_1, area_2) << endl;
        return 0;
    }
    
    // r1^2 + d^2 - 2*r1*dist * cos(a / 2) = r2^2
    ld alpha = 2 * acos((dist * dist + r1 * r1 - r2 * r2) / (2 * dist * r1));
    ld overlap_a = 0.5 * r1 * r1 * (alpha - sin(alpha));
    dbg(alpha * (180 /  PI))

    ld beta = 2 * acos((dist * dist + r2 * r2 - r1 * r1) / (2 * dist * r2));
    ld overlap_b =  0.5 * r2 * r2 * (beta  - sin(beta));
    dbg(alpha * (180 /  PI))

    cout << fixed << setprecision(2) << area_1 + area_2 - overlap_a - overlap_b << endl;
}
