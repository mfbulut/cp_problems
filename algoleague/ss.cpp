#include <iostream>

using namespace std;

char memo_a[1024] = { 0 };
char memo_b[1024] = { 0 };

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.length();

    for (size_t i = 0; i < n; ++i) {
        if(memo_a[a[i]]) {
            if(memo_a[a[i]] != b[i]) {
                cout << "NO";
                return 0;
            }

        } else {
            memo_a[a[i]] = b[i];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if(memo_b[b[i]]) {
            if(memo_b[b[i]] != a[i]) {
                cout << "NO";
                return 0;
            }

        } else {
            memo_b[b[i]] = a[i];
        }
    }

    cout << "YES";
}