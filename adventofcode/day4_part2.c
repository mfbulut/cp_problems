#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

i64 grid[1024 * 32];
i64 size_x = 0;
i64 size_y = 0;

i64 get(i64 x, i64 y) {
    if (x < 0 || y < 0 || x >= size_x) {
        return 0;
    }

    return grid[x + y * size_x];
}

int main() {
    FILE *fp = fopen("adventofcode/day4.txt", "r");

    char str[255];
    while(fscanf(fp, "%s", str) == 1){
        size_x = strlen(str);

        range(i, 0, size_x) {
            if(str[i] == '@') grid[i + size_y * size_x] = 1;
        }

        size_y += 1;
    }

    i64 result = 0;

    start:

    range(y, 0, size_y) {
        range(x, 0, size_x) {
            if(get(x, y)){
                i64 sum = get(x + 1, y) + get(x - 1, y) +  get(x, y + 1) + get(x, y - 1) + get(x + 1, y + 1) + get(x - 1, y - 1) +  get(x - 1, y + 1) + get(x + 1, y - 1);
                if(sum < 4) {
                    result += 1;
                    grid[x + y * size_x] = 0;
                    goto start; // wish c had labeled break
                }
            }
        }
    }

    printf("\nResult: %lld", result);
}
