#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

typedef struct {
    i64 start;
    i64 end;
} Range;

typedef struct {
    Range* data;
    i64 size;
    i64 capacity;
} Vector;

void push(Vector* arr, Range value) {
    if (arr->capacity == 0) {
        arr->capacity = 32;
        arr->data = malloc(arr->capacity * sizeof(Range));
    }

    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(Range));
    }
    arr->data[arr->size++] = value;
}


Range get(Vector* arr, i64 index) {
    if (index >= arr->size) {
        printf("array.get: Index out of bounds\n");
        return (Range){0, 0};
    }
    return arr->data[index];
}

void set(Vector* arr, i64 index, Range value) {
    if (index >= arr->size) {
        printf("array.set: Index out of bounds\n");
        return;
    }
    arr->data[index] = value;
}

void print_array(Vector* arr) {
    range(i, 0, arr->size) {
        printf("%lld-%lld\n", arr->data[i].start, arr->data[i].end);
    }
    printf("\n");
}

Vector v = { 0 };

int is_fresh(i64 val) {
    range(i, 0, v.size) {
        if(v.data[i].start <= val && val <= v.data[i].end) {
            return 1;
        }
    }

    return 0;
}


int main() {
    FILE *fp = fopen("adventofcode/day5.txt", "r");

    i64 start = 0;
    i64 end = 0;

    while(fscanf(fp, "%lld-%lld", &start, &end) == 2){
        push(&v, (Range){start, end});
    }

    print_array(&v);

    i64 result = 0;
    i64 value = 0;

    while(fscanf(fp, "%lld", &value) == 1) {
        if(is_fresh(value)){
            result += 1;
            printf("%lld\n", value);
        }
    }

    printf("\nResult: %lld", result);
}





