#include "libs/data_structures/matrix/matrix.h"

//---------------task 1------------------

void swapRowsWithMinAndMaxEl(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

void test_swapRowsWithMinAndMaxEl1() {
    int a[9] = {1, 2, 3,
                4, 5, 6,
                7, 8, 9};
    matrix m = createMatrixFromArray(a, 3, 3);

    swapRowsWithMinAndMaxEl(m);

    int res[9] = {7, 8, 9,
                  4, 5, 6,
                  1, 2, 3};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_swapRowsWithMinAndMaxEl2() {
    int a[9] = {1, 2, 9,
                4, 5, 6,
                7, 8, 3};
    matrix m = createMatrixFromArray(a, 3, 3);

    swapRowsWithMinAndMaxEl(m);

    int res[9] = {1, 2, 9,
                  4, 5, 6,
                  7, 8, 3};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_swapRowsWithMinAndMaxEl3() {
    int a[] = {1};
    matrix m = createMatrixFromArray(a, 1, 1);

    swapRowsWithMinAndMaxEl(m);

    int res[] = {1};
    matrix mRes = createMatrixFromArray(res, 1, 1);

    assert(areTwoMatricesEqual(m, mRes));
}

//---------------------task 2---------------------

int getMax(int *a, int n) {
    if (n < 1) {
        fprintf(stderr, "empty array");
        exit(1);
    }

    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int getMin(int *a, int n) {
    if (n < 1) {
        fprintf(stderr, "empty array");
        exit(1);
    }

    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMin);
}

void test_sortRowsByMaxElement1() {
    int a[9] = {1, 7, 3,
                4, 5, 6,
                1, 3, 2};
    matrix m = createMatrixFromArray(a, 3, 3);

    sortRowsByMaxElement(m);

    int res[9] = {1, 3, 2,
                  4, 5, 6,
                  1, 7, 3};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_sortRowsByMaxElement2() {
    int a[] = {1, 7, 3, 9,
               4, 5, 6, 2,
               1, 3, 2, 7};
    matrix m = createMatrixFromArray(a, 3, 4);

    sortRowsByMaxElement(m);

    int res[] = {4, 5, 6, 2,
                 1, 3, 2, 7,
                 1, 7, 3, 9};
    matrix mRes = createMatrixFromArray(res, 3, 4);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_sortRowsByMaxElement3() {
    int a[] = {7};
    matrix m = createMatrixFromArray(a, 1, 1);

    sortRowsByMaxElement(m);

    int res[] = {7};
    matrix mRes = createMatrixFromArray(res, 1, 1);

    assert(areTwoMatricesEqual(m, mRes));
}

void test() {
    test_swapRowsWithMinAndMaxEl1();
    test_swapRowsWithMinAndMaxEl2();
    test_swapRowsWithMinAndMaxEl3();

    test_sortRowsByMaxElement1();
    test_sortRowsByMaxElement2();
    test_sortRowsByMaxElement3();

    printf("everything is ok");
}

int main() {
    test();
}