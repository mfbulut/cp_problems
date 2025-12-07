#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
i64 input() { i64 n; scanf("%lld", &n); return n; }

int main() {
    i64 t = input();

    range(test, 0, t) {
        i64 n = input();

        i64 sum = 0;

        range(i, 0, n) {
            i64 num;
            scanf("%lld", &num);
            sum += num;
        }

        range(i, 0, n) {
            printf("%lld ", (i64)(sum * (n - 1 - i)) / n);
        }

        printf("\n");
    }
}