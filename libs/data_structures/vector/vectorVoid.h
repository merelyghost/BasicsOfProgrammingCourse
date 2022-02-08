#ifndef COURSE_VECTORVOID_H
#define COURSE_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct vectorVoid {
    int *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений размера baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное под хранение элементов вектора v, на newCapacity
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// удаляет элементы вектора v из контейнера, не освобождая выделенную память
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору v
void deleteVectorV(vectorVoid *v);

// возвращает значение "истина", если вектор v является пустым, иначе - "ложь"
bool isEmptyV(vectorVoid *v);

// возвращает значение "истина", если вектор v является полным, иначе - "ложь"
bool isFullV(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v);

// добавляет значение, расположенное по адресу source в конец вектора v,
// если вектор заполнен - увеличивает количество выделенной памяти в 2 раза
void pushBackV(vectorVoid *v, void *source);

#endif
