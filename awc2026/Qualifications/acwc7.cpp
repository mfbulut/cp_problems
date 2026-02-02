#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define range(i, a, b) for(i64 i = a; i < b; i++)

#define ar array
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

    int n = 1;
    cin >> n;

    vector<string> heros;

    for (int i = 0; i < n; i++) {
        string hero;
        cin >> hero;
        heros.push_back(hero);
    }

    for (int i = 0; i < n - 1; i++) {
        if(heros[i] == heros[i + 1]){
            heros[i] = "mirror";
        }
    }

    dbg(heros);

    unordered_map<string, ll> mem;
    ll count = 0;

    for (int i = 0; i < n; i++) {
        string hero = heros[i];
        if (!mem[hero] && hero != "mirror") {
            count++;
        }

        mem[hero] = 1;

        if(i + 1 < n && hero == heros[i + 1]){
            cout << "INVALID";
            return 0;
        }

        if(i + 2 < n && hero == heros[i + 2]){
            cout << "INVALID";
            return 0;
        }

        if(i + 3 < n && hero == heros[i + 3]){
            cout << "INVALID";
            return 0;
        }

        if(i + 4 < n && hero == heros[i + 4]) {
            cout << "INVALID";
            return 0;
        }

        bool mirror_used = false;

        if(i + 1 < n && "mirror" == heros[i + 1]){
            mirror_used = true;
        }

        if(i + 2 < n && "mirror" == heros[i + 2]){
            mirror_used = true;
        }

        if(i + 3 < n && "mirror" == heros[i + 3]){
            mirror_used = true;
        }

        if(i + 4 < n && "mirror" == heros[i + 4]) {
            mirror_used = true;
        }

        if(mirror_used && i + 5 < n && hero == heros[i + 5]){
            cout << "INVALID";
            return 0;
        }
    }

    if(count <= 8)
        cout << "VALID";
    else
        cout << "INVALID";
}
