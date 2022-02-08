#ifndef COURSE_VECTORVOID_H
#define COURSE_VECTORVOID_H

#include <limits.h>

typedef struct vectorVoid {
    int *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;



#endif
