#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 2; i <= n; i += 2) {
        sum += i >> __builtin_ctz(i);
    }

    int count = (n - 1) / 2;
    sum += count * (count + 2) + 1;

    cout << sum;
}