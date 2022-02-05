#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора v, на newCapacity
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v из контейнера, не освобождая выделенную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);

// возвращает значение "истина", если вектор v является пустым, иначе - "ложь"
bool isEmpty(vector *v);

// возвращает значение "истина", если вектор v является полным, иначе - "ложь"
bool idFull(vector *v);

// возвращает i-ый элемент вектора v, если такой элемент есть, иначе - "-1"
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v,
// если вектор заполнен - увеличивает количество выделенной памяти в 2 раза
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора v
void popBack(vector *v);



#endif