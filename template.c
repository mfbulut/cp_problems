#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
i64 max(i64 a, i64 b) { return a > b ? a : b; }
i64 min(i64 a, i64 b) { return a > b ? b : a; }
i64 input() { i64 n; scanf("%lld", &n); return n; }
i64* input_array(i64 n) { i64 *arr = (i64*)malloc(n * sizeof(i64)); range(i, 0, n) { scanf("%lld", &arr[i]); } return arr; }

int main() {
    i64 n = input();
    i64* arr = input_array(n);

    range(i, 0, n) {
        printf("%lld ", arr[i]);
    }

    printf("\n");
}






/*
typedef struct {
    i64* data;
    i64 size;
    i64 capacity;
} Vector;

void push(Vector* arr, i64 value) {
    if (arr->capacity == 0) {
        arr->capacity = 32;
        arr->data = malloc(arr->capacity * sizeof(i64));
    }

    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(i64));
    }
    arr->data[arr->size++] = value;
}

i64 pop(Vector* arr) {
    if (arr->size == 0) {
        printf(stderr, "array.pop: Vector is empty\n");
        return 0;
    }
    return arr->data[--arr->size];
}

i64 peek(Vector* arr) {
    if (arr->size == 0) {
        printf(stderr, "array.peek: Vector is empty\n");
        return 0;
    }
    return arr->data[arr->size - 1];
}

i64 get(Vector* arr, size_t index) {
    if (index >= arr->size) {
        printf(stderr, "array.get: Index out of bounds\n");
        return 0;
    }
    return arr->data[index];
}

void set(Vector* arr, size_t index, i64 value) {
    if (index >= arr->size) {
        printf(stderr, "array.set: Index out of bounds\n");
        return;
    }
    arr->data[index] = value;
}

void print_array(Vector* arr) {
    range(i, 0, arr->size) {
        printf("%ld", (long)arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("\n");
}
*/