#include <stdio.h>

typedef int i32;
typedef long long i64;
typedef char* string;
#define range(i,y,x) for(i64 i=(y);(i<(x));(i)++)

int main() {
    i64 n;
    scanf("%lld", &n);

    i64 res = 0;

    while(n >= 5) {
        i64 new = n / 5;
        res += new;
        n = new;
    }

    printf("%lld", res);
}