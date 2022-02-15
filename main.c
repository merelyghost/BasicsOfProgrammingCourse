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

void test_swapRowsWithMinAndMaxEl() {
    test_swapRowsWithMinAndMaxEl1();
    test_swapRowsWithMinAndMaxEl2();
    test_swapRowsWithMinAndMaxEl3();
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

void test_sortRowsByMaxElement() {
    test_sortRowsByMaxElement1();
    test_sortRowsByMaxElement2();
    test_sortRowsByMaxElement3();
}

//----------------task 3-------------

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement1() {
    int a[] = {8, 1, 3,
               4, 5, 6,
               5, 3, 2};
    matrix m = createMatrixFromArray(a, 3, 3);

    sortColsByMinElement(m);

    int res[] = {1, 3, 8,
                 5, 6, 4,
                 3, 2, 5};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_sortColsByMinElement2() {
    int a[] = {8, 1, 3, 0,
               4, 5, 6, 0,
               5, 3, 2, 0};
    matrix m = createMatrixFromArray(a, 3, 4);

    sortColsByMinElement(m);

    int res[] = {0, 1, 3, 8,
                 0, 5, 6, 4,
                 0, 3, 2, 5};
    matrix mRes = createMatrixFromArray(res, 3, 4);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_sortColsByMinElement3() {
    int a[] = {7};
    matrix m = createMatrixFromArray(a, 1, 1);

    sortColsByMinElement(m);

    int res[] = {7};
    matrix mRes = createMatrixFromArray(res, 1, 1);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement1();
    test_sortColsByMinElement2();
    test_sortColsByMinElement3();
}

//-----------------task 4------------------

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "different numbers of rows and columns");
        exit(1);
    }

    matrix product = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            product.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                product.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return (matrix) product;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void test_getSquareOfMatrixIfSymmetric1() {
    int a[] = {1, 2, 3,
               2, 5, 6,
               3, 6, 2};
    matrix m = createMatrixFromArray(a, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    int res[] = {14, 30, 21,
                 30, 65, 48,
                 21, 48, 49};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_getSquareOfMatrixIfSymmetric2() {
    int a[] = {1, 0, 0,
               0, 1, 0,
               0, 0, 1};
    matrix m = createMatrixFromArray(a, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    int res[] = {1, 0, 0,
                 0, 1, 0,
                 0, 0, 1};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric1();
    test_getSquareOfMatrixIfSymmetric2();
}

//---------------task 5-------------------

bool isUnique(long long *a, int n) {
    bool isUnique = true;
    for (int i = 0; i < n && isUnique; i++)
        for (int j = i + 1; j < n && isUnique; j++)
            if (a[i] == a[j])
                isUnique = false;
    return isUnique;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumRows[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumRows[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sumRows, m.nRows))
        transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows1() {
    int a[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9};
    matrix m = createMatrixFromArray(a, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    int res[] = {1, 4, 7,
                 2, 5, 8,
                 3, 6, 9};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_transposeIfMatrixHasNotEqualSumOfRows2() {
    int a[] = {7};
    matrix m = createMatrixFromArray(a, 1, 1);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    int res[] = {7};
    matrix mRes = createMatrixFromArray(res, 1, 1);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_transposeIfMatrixHasNotEqualSumOfRows3() {
    int a[] = {1, 2, 3,
               2, 5, 2,
               3, 2, 4};
    matrix m = createMatrixFromArray(a, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    int res[] = {1, 2, 3,
                 2, 5, 2,
                 3, 2, 4};
    matrix mRes = createMatrixFromArray(res, 3, 3);

    assert(areTwoMatricesEqual(m, mRes));
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows1();
    test_transposeIfMatrixHasNotEqualSumOfRows2();
    test_transposeIfMatrixHasNotEqualSumOfRows3();
}

//------------------------task 6---------------

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

void test_isMutuallyInverseMatrices1() {
    int a[] = {3, 4,
               5, 7};
    matrix m1 = createMatrixFromArray(a, 2, 2);

    int b[] = {7, -4,
               -5, 3};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    assert(isMutuallyInverseMatrices(m1, m2));
}

void test_isMutuallyInverseMatrices2() {
    int a[] = {2, 5, 7,
               6, 3, 4,
               5, -2, -3};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {1, -1, 1,
               -38, 41, -34,
               27, -29, 24};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices1();
    test_isMutuallyInverseMatrices2();
}

void test() {
    test_swapRowsWithMinAndMaxEl();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();

    printf("everything is ok\n");
}

int main() {
    test();
}