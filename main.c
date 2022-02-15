#include "libs/data_structures/matrix/matrix.h"

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

void test() {
    test_swapRowsWithMinAndMaxEl1();
    test_swapRowsWithMinAndMaxEl2();
    test_swapRowsWithMinAndMaxEl3();

    printf("everything is ok");
}

int main() {
    test();
}