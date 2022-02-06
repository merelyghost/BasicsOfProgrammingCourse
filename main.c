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

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 1; i < 5; i++) {
        pushBack(&v, i);
    }

    assert(atVector(&v, 0) == v.data);
    assert(atVector(&v, 2) == v.data + 2);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(4);
    for (int i = 1; i < 5; i++) {
        pushBack(&v, i);
    }

    assert(atVector(&v, 3) == v.data + 3);
}

void test_back_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 1; i < 5; i++) {
        pushBack(&v, i);
    }

    assert(back(&v) == &v.data[3]);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 7);

    assert(back(&v) == v.data);
}

void test_front_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 1; i < 5; i++) {
        pushBack(&v, i);
    }

    assert(front(&v) == &v.data[0]);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 7);

    assert(front(&v) == v.data);
}


void test() {
    test_getVectorValue_EmptyVector();
    test_getVectorValue_NotEmptyVector();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_notEmptyVector();
    test_back_oneElementInVector();
    test_front_notEmptyVector();
    test_front_oneElementInVector();

    printf("everything is ok");
}



int main() {
    test();
}