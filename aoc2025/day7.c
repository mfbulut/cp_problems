#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

int main() {
    FILE *fp = fopen("adventofcode/day7.txt", "r");

    i64 result = 0;
    char current[255] = { 0 };
    char str[255] = { 0 };
    i64 size_x = 0;
    
    while(fgets(str, 255, fp)){
        size_x = strlen(str);
        if (str[size_x - 1] == '\n') size_x--;

        range(i, 0, size_x) {
            if(str[i] == 'S') current[i] = 1;
            
            if(str[i] == '^' && current[i]) {
                current[i - 1] = 1;
                current[i] = 0;
                current[i + 1] = 1;
                result += 1;
            }
        }
        
        range(i, 0, size_x) {
            if(str[i] == 'S') printf("S");
            else if(current[i]) printf("|");
            else if(str[i] == '^') printf("^");
            else printf(" ");
        }
        
        printf("\n");
    }
    
    
    printf("Result: %lld", result);
}   