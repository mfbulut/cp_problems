#include <iostream>
#include <vector>

using namespace std;
#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }

signed main() {
    int t;
    cin >> t;

    while(t--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int l1_x = x2 - x1;
        int l1_y = y2 - y1;

        int l2_x = x3 - x1;
        int l2_y = y3 - y1;

        int cross = l1_x * l2_y - l2_x * l1_y;

        if(cross == 0) {
            cout << "TOUCH" << endl;
        } else if(cross > 0) {
            cout << "LEFT" << endl;
        } else if(cross < 0) {
            cout << "RIGHT" << endl;
        }
    }
}