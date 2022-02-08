#include "vector.h"


bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

void checkBadAllocError(const int *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

void checkIndexOutOfRangeError(size_t size, size_t index) {
    if (index >= size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
}

void checkEmptyVectorError(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "empty vector ");
        exit(1);
    }
}

vector createVector(size_t n) {
    int *a;
    if (n == 0) {
        a = NULL;
    } else {
        a = (int *) malloc(sizeof(int) * n);
        checkBadAllocError(a);
    }
    return (vector) {a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        *v = (vector) {NULL, 0, 0};
    } else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        checkBadAllocError(v->data);

        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
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
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}


int getVectorValue(vector *v, size_t i) {
    checkIndexOutOfRangeError(v->size, i);

    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity ? v->capacity * 2 : 1);
    }

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    checkEmptyVectorError(v);

    v->size--;
}


int *atVector(vector *v, size_t index) {
    checkIndexOutOfRangeError(v->size, index);

    return v->data + index;
}

int *back(vector *v) {
    checkEmptyVectorError(v);

    return v->data + v->size - 1;
}

int *front(vector *v) {
    checkEmptyVectorError(v);

    return v->data;
}