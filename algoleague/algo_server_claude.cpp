#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

const int MAXSUM = 500001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    int cap = min(k, MAXSUM - 1);

    bitset<MAXSUM> dp;
    dp[0] = 1;

    // For each unique value, apply it `count` times using binary lifting
    for (auto& [val, cnt] : freq) {
        // Use powers of 2: apply val*1, val*2, val*4, ...
        // Each "level" doubles the contribution
        int rem = cnt;
        int multiplier = 1;
        while (rem > 0) {
            int take = min(multiplier, rem);
            int shift = val * take;
            if (shift < MAXSUM) {
                dp |= (dp << shift);
            }
            rem -= take;
            multiplier *= 2;
        }
    }

    for (int j = cap; j >= 0; j--) {
        if (dp[j]) {
            cout << j << "\n";
            return 0;
        }
    }
}