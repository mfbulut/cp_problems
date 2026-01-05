#include <iostream>
using namespace std;

int buckets[10] = { 0 };

int main() {
    int n;
    cin >> n;

    while (n > 0) {
        buckets[n % 10] += 1;
        n /= 10;
    }

    for (int i = 1; i < 10; i++) {
        if(buckets[i]){
            cout << i;
            buckets[i] -= 1;
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        while(buckets[i]){
            buckets[i] -= 1;
            cout << i;
        }
    }
}
