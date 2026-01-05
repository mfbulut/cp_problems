#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;
#define range(i,a,b) for(u64 i=(a);(i<(b));(i)++)
u64 min(u64 a, u64 b) { return a > b ? b : a; }
int toggleBit(int N, int K) { return (N ^ (1 << K)); }

u64 goal = 0;
u64 count = 0;
u64 buttons[10000] = {0};

// Code from advent of compiler optimization series
u64 countSetBits(u64 n)
{
    u64 count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

u64 find_buttons() {
    u64 best = 10000;
    
    u64 total = 1 << count;
    
    for (u64 mask = 1; mask < total; mask++) {
        u64 res = 0;
        
        for (u64 i = 0; i < count; i++) {
            if (mask & (1 << i)) {
                res ^= buttons[i];
            }
        }
        
        if(res == goal) {
            best = min(best, countSetBits(mask));
        }
    }
    
    return best;
}


u64 sum = 0;

int main() {
    FILE *fp = fopen("adventofcode/day10.txt", "r");
    
    start:
    goal = 0;
    count = 0;
    range(i, 0, 10000) buttons[i] = 0;
    
    u64 bit = 0;
    char c = 0;
    while (fscanf(fp, "%c", &c) == 1) {        
        if(c == '\n') break;
        else if(c == '.') bit++;
        else if(c == '#')  goal = toggleBit(goal, bit++);
        else if(c == '(') {
            u64 num;
            while (fscanf(fp, "%lld", &num) == 1) {
                buttons[count] = toggleBit(buttons[count], num);
                fscanf(fp, ",");
            }
            count++;
        }
    }
    
    if(goal == 0) {
        printf("Sum %lld\n", sum);
        return 0;
    }
    
    printf("Goal: %lld\n", goal);
    printf("Min Press: %lld\n\n", find_buttons());
    sum += find_buttons();
    
    goto start;
}


