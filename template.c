#include <stdio.h>

typedef int i32;
typedef long long i64;
typedef char* string;
#define range(i,y,x) for(i64 i=(y);(i<(x));(i)++)

int main() {
    i64 n;
    scanf("%lld", &n);

    range(i, 0, 10) {
        printf("%lld ", i);
    }
}