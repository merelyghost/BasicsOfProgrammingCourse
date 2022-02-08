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

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "empty vector ");
        exit(1);
    }
    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v)) {
        reserveV(v, v->capacity ? v->capacity * 2 : 1);
    }
    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    v->size++;
}

