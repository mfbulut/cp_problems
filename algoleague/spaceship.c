#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
#define ABS(a) (((a) < 0) ? -(a) : (a))
i64 input() { i64 n; scanf("%lld", &n); return n; }

typedef struct {
    i64 x;
    i64 y;
    i64 z;
} vec3;

i64 dist(vec3 a, vec3 b) {
    return ABS(a.x - b.x) + ABS(a.y - b.y) + ABS(a.z - b.z);
}

i64 factorial(i64 n) {
    int fact = 1, i;

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int main() {
    i64 t = input();

    range(test, 0, t) {
        i64 n = input();
        vec3 arr[n];
        range(i, 0, n) { scanf("%lld %lld %lld", &arr[i].x, &arr[i].y ,&arr[i].z); }

        i64 sum = 0;

        range(i, 0, n) {
            range(j, i + 1, n) {
                sum += dist(arr[i], arr[j]);
            }
        }

        sum *= 2 * factorial(n - 1) + 1;

        printf("%lld\n", sum);
    }
}