#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

int main() {
    FILE *fp = fopen("adventofcode/day12.txt", "r");

    int x;
    int y;
    int num_blocks;

    char arr[64];
    int result = 0;

    while (1) {
        char count = fscanf(fp, "%dx%d: ", &x, &y);

        if(count == 1) {
            fscanf(fp, ":\n");
            range(i, 0, 3) {
                fscanf(fp, "%s\n", arr);
            }

            num_blocks = x;
        } else if (count == 2) {
            int sum =  0;
            printf("%dx%d: ", x,y);
            range(i, 0, num_blocks + 1){
                int num =  0;
                fscanf(fp, "%d", &num);
                printf("%d ", num);
                sum += num;
            }
            printf("\n");


            if((x / 3) * (y / 3) >= sum)
                result++;

        } else {
            break;
        }
    }

    printf("%d\n", result);
}