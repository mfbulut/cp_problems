#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')' << endl; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}' << endl; }

signed main() {
    int n;
    cin >> n;

    vector<pair<int, int>> items(n);
    for (auto &[duration, deadline] : items)
        cin >> duration >> deadline;

    int cur = 0;
    int res = 0;

    sort(items.begin(), items.end());

    for (auto [duration, deadline] : items) {
        cur += duration;
        res += deadline - cur;
    }

    cout << res;
}