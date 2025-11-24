#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(((x)>=(y))?(i<=(x)):(i>=x));(((x)>=(y))?((i)++):((i)--)))
#define foreach(i, A) for(int _keep=1, _count=0,_size=sizeof (A) / sizeof *(A); _keep && _count != _size; _keep = !_keep, _count++) for(i = (A)+_count; _keep; _keep = !_keep)
#define len(a) (sizeof(a) / sizeof((a)[0]))
#define log(x, fmt, ...) if(x){printf("%s@%d: " fmt "\n", __FILE__, __LINE__,__VA_ARGS__);}

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