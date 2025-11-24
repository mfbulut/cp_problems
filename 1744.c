#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(((x)>=(y))?(i<=(x)):(i>=x));(((x)>=(y))?((i)++):((i)--)))
#define len(a) (sizeof(a) / sizeof((a)[0]))
#define foreach(_item_, _array_) for(size_t i = 0u, _keep_ = 1u; _keep_ && i < len(_array_); _keep_ = !_keep_, i++) for (_item_ = _array_[i]; _keep_; _keep_ = !_keep_)
#define log(fmt, ...) printf("%s@%d: " fmt "\n", __FILE__, __LINE__,__VA_ARGS__);

// since we know a,b < 500
#define MAX_VALUE 501
i64 memo[MAX_VALUE][MAX_VALUE];

i64 min_cuts(i64 a, i64 b) {
    if (a > b) {
        i64 temp = a;
        a = b;
        b = temp;
    }

    if (a == b) {
        return 0;
    }

    if (memo[a][b] != -1) {
        return memo[a][b];
    }

    i64 smallest = 9999999;

    for (i64 i = 1; i < a; ++i) {
        i64 res = 1 + min_cuts(i, b) + min_cuts(a - i, b);
        if(res < smallest) smallest = res;
    }

    for (i64 i = 1; i < b; ++i) {
        i64 res = 1 + min_cuts(a, i) + min_cuts(a, b - i);
        if(res < smallest) smallest = res;
    }

    return memo[a][b] = smallest;
}

int main() {
    for (int i = 0; i < MAX_VALUE; ++i) {
        for (int j = 0; j < MAX_VALUE; ++j) {
            memo[i][j] = -1;
        }
    }

    i64 a;
    scanf("%lld", &a);

    i64 b;
    scanf("%lld", &b);

    i64 result = min_cuts(a, b);

    printf("%lld", result);
}
