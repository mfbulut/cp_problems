#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using i64 = long long;
using namespace std;

int main() {
    i64 a;
    cin >> a;

    i64 b;
    cin >> b;

    vector<i64> arr_a(a);
    for (i64 i = 0; i < a; i++) {
        cin >> arr_a[i];
    }

    vector<i64> arr_b(b);
    unordered_map<i64, i64> map_b;
    for (i64 i = 0; i < b; i++) {
        cin >> arr_b[i];
        map_b[arr_b[i]] = i;
    }

    i64 last_a = 0;
    i64 last_b = 0;
    i64 sum = 0;

    for (i64 i = 0; i < a; i++) {
        i64 a_value = arr_a[i];
        if (map_b.find(a_value) != map_b.end()) {

            i64 sum_a = 0;
            for (i64 j = last_a; j < i; j++) {
                sum_a += arr_a[j];
            }

            i64 sum_b = 0;
            for (i64 j = last_b; j < map_b[a_value]; j++) {
                sum_b += arr_b[j];
            }

            sum += max(sum_a, sum_b) + a_value;
            sum = sum % 1000000007;

            last_a = i + 1;
            last_b = map_b[a_value] + 1;
        }
    }

    i64 sum_a = 0;
    for (i64 i = last_a; i < a; i++) {
        sum_a += arr_a[i];
    }

    i64 sum_b = 0;
    for (int i = last_b; i < b; i++) {
        sum_b += arr_b[i];
    }

    sum += max(sum_a, sum_b);
    sum = sum % 1000000007;

    cout << sum;
}
