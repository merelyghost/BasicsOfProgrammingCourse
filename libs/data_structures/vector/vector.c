#include "vector.h"


// first ---------------------------
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

// second --------------------------

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return (i < v->size) ? v->data[i] : -1;
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "empty vector ");
        exit(1);
    }
    v->size--;
}