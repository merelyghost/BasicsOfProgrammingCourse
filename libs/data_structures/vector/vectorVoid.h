#ifndef COURSE_VECTORVOID_H
#define COURSE_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vectorVoid {
    int *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное под хранение элементов вектора v, на newCapacity
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// удаляет элементы вектора v из контейнера, не освобождая выделенную память
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору v
void deleteVectorV(vectorVoid *v);

#endif
