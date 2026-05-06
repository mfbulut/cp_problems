#include <iostream>
#include <vector>

using namespace std;
#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }

signed main() {
    int n;
    cin >> n;

    if (n % 4 == 0) {
        cout << "YES" << endl;
        cout << n / 2 << endl;
        for(int i = 1; i <= n; ++i) {
            if(i % 4 == 1 || i % 4 == 0)
                cout << i << " ";

        }
        cout << endl;

        cout << n / 2 << endl;
        for(int i = 1; i <= n; ++i) {
            if(i % 4 == 2 || i % 4 == 3)
                cout << i << " ";
        }
        cout << endl;
    } else if (n % 4 == 3) {
        cout << "YES" << endl;
        cout << n / 2 + 1 << endl;

        cout << "1 2 ";
        for(int i = 4; i <= n; ++i) {
            if(i % 4 == 0 || i % 4 == 3)
                cout << i << " ";

        }
        cout << endl;

        cout << n / 2 << endl;
        cout << "3 ";
        for(int i = 4; i <= n; ++i) {
            if(i % 4 == 1 || i % 4 == 2)
                cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "NO";
    }

}