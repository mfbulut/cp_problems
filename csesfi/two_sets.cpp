#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;

    if (sum % 2) {
        cout << "NO\n";
        return 0;
    }

    vector<int> a;
    vector<int> b;

    if (n % 4 == 0) {
        for (int i = 1; i <= n; i += 4) {
            a.push_back(i);
            a.push_back(i + 3);
            b.push_back(i + 1);
            b.push_back(i + 2);
        }
    } else { // n % 4 == 3
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);

        for (int i = 4; i <= n; i += 4) {
            a.push_back(i);
            a.push_back(i + 3);
            b.push_back(i + 1);
            b.push_back(i + 2);
        }
    }

    cout << "YES\n";

    cout << a.size() << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n";

    cout << b.size() << "\n";
    for (int x : b) cout << x << " ";
    cout << "\n";
}