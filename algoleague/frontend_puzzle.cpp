#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

int input() { int n; cin >> n; return n;}
int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

    int n = input();

    while (n--) {
        int x = input();
        int y = input();
        int num = gcd(x, y);

        if (num == 1) {
            cout << "-1\n";
            continue;
        }

        for (int p = 2; p * p <= num; p++) {
            if (num % p == 0) {
                cout << p << " ";
                do { num /= p; } while (num % p == 0);
            }
        }

        if (num > 1) cout << num << " ";

        cout << '\n';
    }
}
