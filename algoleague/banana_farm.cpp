#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int shift_count = (32 - __builtin_clz(n)) - 1;
    int add_count = __builtin_popcount(n) - 1;

    cout << shift_count + add_count;
}