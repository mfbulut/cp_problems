#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

char str[255] = { 0 };
i64 len = 0;

i64 find_largest(i64 a, i64 b) {
    i64 value = -1;
    i64 index = -1;

    range(i, a, b) {
        i64 current = str[i];

        if(current > value) {
            value = current;
            index = i;
        }
    }

    return index;
}

i64 get(i64 x) {
    return str[x] - '0';
}

int main() {
    FILE *fp = fopen("adventofcode/day3.txt", "r");

    i64 result = 0;

    while(fscanf(fp, "%s", str) == 1){
        len = strlen(str);

        i64 mult = 100000000000; // 10^11
        i64 last_id = 0;
        i64 value = 0;

        range(i, 0, 12) {
            i64 new_id = find_largest(last_id, len - 11 + i);
            value += mult * get(new_id);
            mult /= 10;
            last_id = new_id + 1;
        }

        printf("%lld\n", value);
        result += value;
    }

    printf("Result: %lld", result);
}
