#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *a;
    if (n == 0) {
        a = NULL;
    } else {
        a = (void *) malloc(baseTypeSize * n);
        if (a == NULL) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
    }
    return (vectorVoid) {a, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        *v = (vectorVoid) {NULL, 0, 0, v->baseTypeSize};
    } else {
        v->data = (void *) realloc(v->data, v->baseTypeSize * newCapacity);
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

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}