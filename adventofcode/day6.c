#include <stdio.h>
#include <stdlib.h>

// only part 2 bc part 1 was so eays I did it with multicursor magic

typedef long long i64;
#define range(i,a,b) for(int i=(a);(i<(b));(i)++)
char input() { char n; scanf("%c", &n); return n; }

#define width 3763
#define height 5
char map[width][height];

i64 carpma(int start, int end) {
    i64 result = 1;
    
    range(x, start, end) {
        i64 number = 0;
        
        range(y, 0, height) {
            if(map[x][y] == ' ') continue;
            
            number += map[x][y] - '0';
            if(map[x][y + 1] < '0' || '9' < map[x][y + 1]) break;
            number *= 10;
        }
        
        result *= number;
    }

    return result;
}

i64 toplama(int start, int end) {
    i64 result = 0;

    range(x, start, end) {
        i64 number = 0;
        
        range(y, 0, height) {
            if(map[x][y] == ' ') continue;
            
            number += map[x][y] - '0';
            if(map[x][y + 1] < '0' || '9' < map[x][y + 1]) break;
            number *= 10;
        }
        
        result += number;
    }

    return result;
}

int main() {
    range(y, 0, height) {
        range(x, 0, width) {
            char c = input();
            if(c != '\n'){
                map[x][y] = c;
            }
        }
    }
    
    i64 result = 0;
    
    range(x, 0, width - 1) {
        i64 start_x = x;
        
        if(map[x][height - 1] == '*') {
            x += 1;
            while(map[x][height - 1] == ' ') x += 1;
            x -= 1;
            
            result += carpma(start_x, x);
        }
        
        if(map[x][height - 1] == '+') {
            x += 1;
            while(map[x][height - 1] == ' ') x += 1;
            x -= 1;
            
            result += toplama(start_x, x);
        }

    }
    
    printf("Result %lld\n", result);
}