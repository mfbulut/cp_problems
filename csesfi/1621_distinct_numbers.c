#include <stdio.h>
#include <stdlib.h>

#pragma GCC optimize ("O3")
typedef long long i64;

#define fori(a, b) for(i64 i = a; i < b; i++)
#define forj(a, b) for(i64 j = a; j < b; j++)
#define fork(a, b) for(i64 k = a; k < b; k++)

i64 max(i64 a, i64 b) { return a > b ? a : b; }
i64 min(i64 a, i64 b) { return a > b ? b : a; }
i64 input() { i64 n; scanf("%lld", &n); return n; }


struct { i64 k, v, u; } t[2000003];

#define HASH(k) ((((i64)(k) * 2654435761LL) ^ ((i64)(k) >> 16)) % 2000003)

i64 map_get(i64 k) {
    for (i64 i = HASH(k), cnt = 0; t[i].u && cnt < 2000003; i = (i + 1) % 2000003, cnt++){
        if (t[i].k == k) return t[i].v;
    }
    return -1;
}

void map_set(i64 k, i64 v) {
    i64 i = HASH(k);
    while (t[i].u && t[i].k != k) i = (i + 1) % 2000003;
    t[i].u = 1; t[i].k = k; t[i].v = v;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

    i64 n = input();
    i64 count = 0;

    fori(0, n) {
        i64 num = input();
        if(map_get(num) < 0) {
            map_set(num, 1);
            count++;
        }
    }

    printf("%lld", count);
}
