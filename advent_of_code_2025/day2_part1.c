#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<=(b));(i)++)

i64 digits(i64 x) {
    i64 log = 0;
    while (x >= 10) {
        x /= 10;
        log++;
    }
    return log + 1;
}

static const i64 pow[19] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    100000000000000000,
    1000000000000000000
};

int main() {
    FILE *fp = fopen("adventofcode/day2.txt", "r");

    i64 result = 0;

    i64 start = 0;
    i64 end = 0;
    char comma = 0;

    do {
        fscanf(fp, "%lld-%lld", &start, &end);

        range(i, start, end) {
            i64 digit_count = digits(i);
            if(digit_count % 2 == 1) continue;

            i64 num = pow[digit_count / 2];
            i64 left = i / num;
            i64 right = i - left * num;

            if(left == right) {
                result += i;
                // printf("%lld\n", i);
            }

        }


    } while(fscanf(fp, "%c", &comma) == 1);

    printf("%lld\n", result);
}
