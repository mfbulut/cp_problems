#include <stdio.h>

typedef char* string;
typedef int i32;
typedef long long i64;
#define range(i,y,x) for(i64 i=(y);(i<=(x));(i)++)

int main() {
    i64 n;
    scanf("%lld", &n);

    while(n != 1) {
        printf("%lld ", n);

        if(n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }

    printf("%lld ", n);
}