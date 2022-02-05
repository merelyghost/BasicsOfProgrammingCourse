#include "vector.h"

vector createVector(size_t n) {
    int *a;
    if (n == 0) {
        a = NULL;
    } else {
        a = (int *) malloc(sizeof(int) * n);
        if (a == NULL) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
    }
    return (vector) {a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        *v = (vector) {NULL, 0, 0};
    } else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        } else {
            v->capacity = newCapacity;
            if (newCapacity < v->size)
                v->size = newCapacity;
        }
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->capacity = 0;
    v->size = 0;
}