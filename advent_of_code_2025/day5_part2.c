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

void print_array(Vector* arr) {
    range(i, 0, arr->size) {
        printf("%lld-%lld\n", arr->data[i].start, arr->data[i].end);
    }
    printf("\n");
}

Vector v = { 0 };

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

    range(i, 0, v.size) {
        range(j, i + 1, v.size) {
            if(v.data[i].start <= v.data[j].start && v.data[i].end >= v.data[j].end) {
                v.data[j].start = 0;
                v.data[j].end = -1;
            } else if(v.data[j].start <= v.data[i].start && v.data[j].end >= v.data[i].end) {
                v.data[i].start = 0;
                v.data[i].end = -1;
            } else if (v.data[i].start <= v.data[j].start && v.data[i].end >= v.data[j].start && v.data[i].end <= v.data[j].end) {
                v.data[j].start = v.data[i].end + 1;
            } else if (v.data[j].start <= v.data[i].start && v.data[j].end >= v.data[i].start && v.data[j].end <= v.data[i].end) {
                v.data[i].start = v.data[j].end + 1;
            }
        }
    }

    print_array(&v);

    range(i, 0, v.size) {
        result += v.data[i].end - v.data[i].start + 1;
    }

    printf("\nResult: %lld", result);
}
