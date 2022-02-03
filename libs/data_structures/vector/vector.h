#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdio.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

#endif