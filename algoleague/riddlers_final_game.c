#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;
u64 input() { u64 n; scanf("%lld", &n); return n; }
char memo[1000001];

u64 power(u64 base, u64 exp, u64 mod) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}

int main() {
    u64 x = input();
    u64 y = input();

    x = x % y;
    u64 last = x;

    while(x != 0) {
        last = x;
        x = power(x, x, y);

        if(last == x) break;

        if(memo[x]) {
            printf("IMPOSSIBLE");
            return 0;
        }

        memo[x] = 1;
    }

    printf("%lld", x);
}




