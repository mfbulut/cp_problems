#include <stdio.h>
#include <stdlib.h>

#define count 7

typedef struct {
    int color;
    int value;
} Tile;

Tile tiles[count];

#define SET_BIT(var, bit)    ((var) |= (1U << (bit)))
#define GET_BIT(var, bit)    (((var) >> (bit)) & 1U)
#define range(i,a,b) for(int i=(a); i < (b); i++)
int input() { int n; scanf("%d", &n); return n; }

char* colors[5] = {
    "",
    "Red",
    "Blue",
    "Yellow",
    "Black",
};


int calculate() {
    range(i, 0, count) {
        printf("tile: %s %d\n", colors[tiles[i].color], tiles[i].value);
    }

    return 0;
}





int compareTile(const void *a, const void *b) {
    Tile *A = (Tile*)a;
    Tile *B = (Tile*)b;
    return A->value - B->value;
}

int main() {

    range(i, 0, count) {
        tiles[i].color = input();
        tiles[i].value = input();
    }

    qsort(tiles, count, sizeof(Tile), compareTile);

    int result = calculate();
    printf("Result: %d\n", result);
}
