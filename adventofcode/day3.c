#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

int main() {
    FILE *fp = fopen("adventofcode/day3.txt", "r");

    char str[255];
    i64 result = 0;

    while(fscanf(fp, "%s", str) == 1){
        i64 len = strlen(str);

        int first = -1;
        int first_id = -1;

        range(i, 0, len - 1) {
            i64 value = str[i] - '0';

            if(value > first) {
                first = value;
                first_id = i;
            }
        }

        int second = -1;

        range(i, first_id + 1, len) {
            i64 value = str[i] - '0';

            if(value > second) {
                second = value;
            }
        }

        printf("%lld%lld \n", first, second);

        result += first * 10 + second;
    }

    printf("Result: %lld", result);
}
