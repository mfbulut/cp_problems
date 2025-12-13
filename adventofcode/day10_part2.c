#include <stdio.h>
#include <stdlib.h>
typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

typedef struct {
    i64 a[10];
} SmallArray;

i64 btn_count = 0;
SmallArray btn[13] = {0};
SmallArray voltages = {0};

void output_lp_format() {
    printf("Minimize\n");
    printf("obj: n0");
    range(i, 1, btn_count) {
        printf(" + n%lld", i);
    }
    printf("\n");

    printf("Subject To\n");
    i64 constraint_num = 0;
    range(i, 0, 10) {
        if(voltages.a[i]) {
            printf("c%lld: ", constraint_num++);
            char first = 1;
            range(j, 0, btn_count) {
                if(btn[j].a[i]) {
                    if(!first) printf(" + ");
                    printf("n%lld", j);
                    first = 0;
                }
            }
            printf(" = %lld\n", voltages.a[i]);
        }
    }

    printf("Bounds\n");
    range(i, 0, btn_count) {
        printf("n%lld >= 0\n", i);
    }

    printf("General\n");
    range(i, 0, btn_count) {
        printf("n%lld\n", i);
    }

    printf("End\n");
}

int main() {
    FILE *fp = fopen("adventofcode/day10.txt", "r");
    i64 my_exit = 0;

    start:
    voltages = (SmallArray){0};
    range(i, 0, 13) btn[i] = (SmallArray){ 0 };
    btn_count = 0;

    char c = 0;
    for(;;) {
        if(fscanf(fp, "%c", &c) == -1) {
            output_lp_format();
            return 0;
        }

        if(c == '\n') break;
        else if(c == '(') {
            i64 num;
            while (fscanf(fp, "%lld", &num) == 1) {
                btn[btn_count].a[num] = 1;
                fscanf(fp, ",");
            }
            btn_count++;
        } else if(c == '{') {
            i64 num;
            i64 i = 0;
            while (fscanf(fp, "%lld", &num) == 1) {
                voltages.a[i++] = num;
                fscanf(fp, ",");
            }
        }
    }

    output_lp_format();
    printf("\n");

    goto start;
}

// install glpk first

/*

#!/bin/bash

./prog > all_out.lp

awk 'BEGIN {n=1; f="job_" n ".lp"} /Minimize/ {p=1} p {print > f} /End/ {p=0; close(f); n++; f="job_" n ".lp"}' all_out.lp

total=0

for file in job_*.lp
do
    glpsol --lp "$file" -o sol.txt > /dev/null 2>&1
    val=$(grep "Objective" sol.txt | awk '{print $4}')
    total=$((total + val))
    rm "$file" sol.txt
done

echo "Total: $total"

*/
