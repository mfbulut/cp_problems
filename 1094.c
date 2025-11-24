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

    if(n == 1) {
        printf("%lld", 0);
        return 0;
    }

    i64 result = 0;
    i64 array[n];

    range(i, 0, n - 1) {
        scanf("%lld", &array[i]);
    }

    range(i, 1, n - 1) {
        if(array[i] < array[i - 1]) {
            result += array[i - 1] - array[i];
            array[i] = array[i - 1];
        }
    }

    printf("%lld\n", result);
}