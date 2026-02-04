#include <stdio.h>

typedef int i32;
typedef long long i64;
typedef char* string;
#define range(i,y,x) for(i64 i=(y);(i<(x));(i)++)
#define max(a,b) (((a)>(b))?(a):(b))

i64 get(i64 x, i64 y) {
    i64 n = max(x, y);
    if(n % 2 == 1) n += 1;

    i64 result = n * n;

    i64 mx = 1;
    i64 my = n;

    if(mx == x && my == y) return result;

    if(x <= mx + (n - 1) && my == y) {
        return result - (x - mx);
    } else {
        mx += (n - 1);
        result -= (n - 1);
    }

    if(mx == x) {
        return result - (my - y);
    } else {
        my -= (n - 1);
        result -= (n - 1);
    }

    mx -= 1;
    result -= 1;
    if(mx == x && my == y) return result;

    if(mx == x) {
        return result - (y - my);
    } else {
        my -= (n - 2);
        result -= (n - 2);
    }

    return result - (mx - x);
}

int main() {
    i64 n;
    scanf("%lld", &n);

    range(i, 0, n) {
        i64 x;
        i64 y;
        scanf("%lld", &y);
        scanf("%lld", &x);

        printf("%lld\n", get(x, y));
    }
}

