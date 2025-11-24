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

int main() {
    i64 n;
    scanf("%lld", &n);

    i64 result = n * (n + 1) / 2;

    range(i, 1, n - 1) {
        i64 num;
        scanf("%lld", &num);
        result -= num;
    }

    printf("%lld", result);
}