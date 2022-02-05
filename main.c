#include <assert.h>
#include "libs/data_structures/vector/vector.h"


void test_getVectorValue_EmptyVector() {
    vector v = createVector(0);
    assert(getVectorValue(&v, 2) == -1);
}

void test_getVectorValue_NotEmptyVector() {
    vector v = createVector(5);
    for (int i = 1; i < 5; i++) {
        pushBack(&v, i);
    }
    assert(getVectorValue(&v, 2) == 3);
    assert(getVectorValue(&v, 4) == -1);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(v.capacity == 1);
    assert(v.size == 1);
    assert(v.data[0] == 5);
}

void test_pushBack_fullVector() {
    vector v = createVector(3);
    for (int i = 1; i < 5; i++) {
        pushBack(&v, i);
    }

    assert(v.capacity == 6);
    assert(v.size == 4);
    assert(v.data[3] == 4);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() {
    test_getVectorValue_EmptyVector();
    test_getVectorValue_NotEmptyVector();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();

    printf("everything is ok");
}



int main() {
    test();
}