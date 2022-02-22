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

// утечка памяти, нельзя в одну строку, освободить
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix product = mulMatrices(m1, m2);
    bool isInverse = isEMatrix(product);

    freeMemMatrix(product);

    return isInverse;
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

//-----------------task 7--------------

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int size = m.nRows + m.nCols - 1;
    int maxElements[size];

    for (int i = 0; i < size; i++)
        maxElements[i] = INT_MIN;

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            int index = i - j + m.nRows - 1;
            maxElements[index] = max(maxElements[index], m.values[j][i]);
        }
    }

    long long sum = getSum(maxElements, size);
    return sum;
}


void test_findSumOfMaxesOfPseudoDiagonal1() {
    int a[] = {2, 5, 7, 1,
               6, 3, 4, 2,
               5, -2, -3, 5};
    matrix m = createMatrixFromArray(a, 3, 4);

    long long sum = findSumOfMaxesOfPseudoDiagonal(m);
    assert(sum == 27);
}

void test_findSumOfMaxesOfPseudoDiagonal2() {
    int a[] = {};
    matrix m = createMatrixFromArray(a, 0, 0);

    long long sum = findSumOfMaxesOfPseudoDiagonal(m);
    assert(sum == 0);
}

void test_findSumOfMaxesOfPseudoDiagonal3() {
    int a[] = {2, 5, 7,
               6, 3, 4,
               5, -2, -3,
               1, 8, 7};
    matrix m = createMatrixFromArray(a, 4, 3);

    long long sum = findSumOfMaxesOfPseudoDiagonal(m);
    assert(sum == 31);
}

void test_findSumOfMaxesOfPseudoDiagonal4() {
    int a[] = {-1, -7, -4,
               -6, -2, -4,
               -5, -2, -3};
    matrix m = createMatrixFromArray(a, 3, 3);

    long long sum = findSumOfMaxesOfPseudoDiagonal(m);
    assert(sum == -16);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal1();
    test_findSumOfMaxesOfPseudoDiagonal2();
    test_findSumOfMaxesOfPseudoDiagonal3();
    test_findSumOfMaxesOfPseudoDiagonal4();
}

//-----------------task 8--------------

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinInArea(matrix m) {
    position minPos = getMaxValuePos(m);
    int minEl = m.values[minPos.rowIndex][minPos.colIndex];

    int left = minPos.colIndex;
    int right = minPos.colIndex;
    for (int i = minPos.rowIndex - 1; i >= 0; i--) {
        left = left > 0 ? left - 1 : left;
        right = right < m.nCols - 1 ? right + 1 : right;
        minEl = min(getMin(&m.values[i][left], right - left + 1), minEl);
    }

    return minEl;
}

void test_getMinInArea1() {
    int a[] = {2, 7, 5,
               1, 8, 4,
               9, 11, 3};
    matrix m = createMatrixFromArray(a, 3, 3);

    assert(getMinInArea(m) == 1);
}

void test_getMinInArea2() {
    int a[] = {2, 7, 5, -7,
               1, 8, 20, 10,
               9, 11, 3, 4};
    matrix m = createMatrixFromArray(a, 3, 4);

    assert(getMinInArea(m) == -7);
}

void test_getMinInArea3() {
    int a[] = {2};
    matrix m = createMatrixFromArray(a, 1, 1);

    assert(getMinInArea(m) == 2);
}

void test_getMinInArea() {
    test_getMinInArea1();
    test_getMinInArea2();
    test_getMinInArea3();
}

//------------------------task 9--------------

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++) {
        distance += (float) (a[i] * a[i]);
    }
    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float resultsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        resultsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        for (int j = i; j > 0 && resultsCriteria[j - 1] > resultsCriteria[j]; j--) {
            swap(&resultsCriteria[j - 1], &resultsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}


void test_sortByDistances1() {
    int a[] = {6, 8, 9, 2,
               10, 11, 5, 1,
               7, 12, 3, 4};
    matrix m1 = createMatrixFromArray(a, 3, 4);

    sortByDistances(m1);

    int b[] = {6, 8, 9, 2,
               7, 12, 3, 4,
               10, 11, 5, 1};
    matrix m2 = createMatrixFromArray(b, 3, 4);

    assert(areTwoMatricesEqual(m1, m2));
}


void test_sortByDistances2() {
    int a[] = {6, 8, 9, 2};
    matrix m1 = createMatrixFromArray(a, 1, 4);

    sortByDistances(m1);

    int b[] = {6, 8, 9, 2};
    matrix m2 = createMatrixFromArray(b, 1, 4);

    assert(areTwoMatricesEqual(m1, m2));
}

void test_sortByDistances3() {
    int a[] = {6,
               8,
               9,
               2};
    matrix m1 = createMatrixFromArray(a, 4, 1);

    sortByDistances(m1);

    int b[] = {2,
               6,
               8,
               9};
    matrix m2 = createMatrixFromArray(b, 4, 1);

    assert(areTwoMatricesEqual(m1, m2));
}

void test_sortByDistances() {
    test_sortByDistances1();
    test_sortByDistances2();
    test_sortByDistances3();
}

//------------------task 10--------

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int countOfUnique = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            countOfUnique++;
    }

    return countOfUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumRows[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumRows[i] = getSum(m.values[i], m.nCols);

    return countNUnique(sumRows, m.nRows);
}

void test_countEqClassesByRowsSum1() {
    int a[] = {7, 1,
               2, 7,
               5, 3,
               1, 1,
               2, 0,
               7, 8};
    matrix m = createMatrixFromArray(a, 6, 2);

    assert(countEqClassesByRowsSum(m) == 4);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum2() {
    int a[] = {7, 1, 2, 7};
    matrix m = createMatrixFromArray(a, 1, 4);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum3() {
    int a[] = {7,
               10,
               5,
               1,
               2,
               7};
    matrix m = createMatrixFromArray(a, 6, 1);

    assert(countEqClassesByRowsSum(m) == 5);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum1();
    test_countEqClassesByRowsSum2();
    test_countEqClassesByRowsSum3();
}

//----------------task 11---------------

int getNSpecialElement(matrix m) {
    int countSpecialEl = 0;

    for (int i = 0; i < m.nCols; i++) {
        int sumCol = 0;
        int maxEl = m.values[0][i];

        for (int j = 0; j < m.nRows; j++) {
            if (m.values[j][i] > maxEl)
                maxEl = m.values[j][i];
            sumCol += m.values[j][i];
        }
        sumCol -= maxEl;

        if (maxEl > sumCol)
            countSpecialEl++;
    }

    return countSpecialEl;
}

void test_getNSpecialElement1() {
    int a[] = {3, 5, 5, 4,
               2, 3, 6, 7,
               12, 2, 1, 2};
    matrix m = createMatrixFromArray(a, 3, 4);

    assert(getNSpecialElement(m) == 2);
}

void test_getNSpecialElement2() {
    int a[] = {3};
    matrix m = createMatrixFromArray(a, 1, 1);

    assert(getNSpecialElement(m) == 1);
}

void test_getNSpecialElement3() {
    int a[] = {7, 7, 7, 7,
               7, 7, 7, 7,
               7, 7, 7, 7};
    matrix m = createMatrixFromArray(a, 3, 4);

    assert(getNSpecialElement(m) == 0);
}

void test_getNSpecialElement4() {
    int a[] = {3, 4, 8, 7};
    matrix m = createMatrixFromArray(a, 1, 4);

    assert(getNSpecialElement(m) == 4);
}

void test_getNSpecialElement() {
    test_getNSpecialElement1();
    test_getNSpecialElement2();
    test_getNSpecialElement3();
    test_getNSpecialElement4();
}


//------------task 12-----------

position getLeftMin(matrix m) {
    int minEl = m.values[0][0];
    position minPos = {0, 0};

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            if (m.values[j][i] < minEl) {
                minEl = m.values[j][i];
                minPos = (position) {j, i};
            }
        }
    }

    return minPos;
}

void test_getLeftMin() {
    int a[] = {3, 2, 7,
               2, 7, 2};
    matrix m = createMatrixFromArray(a, 2, 3);

    position pos = getLeftMin(m);

    assert(pos.rowIndex == 1);
    assert(pos.colIndex == 0);
}


void swapPenultimateRow(matrix m) {
    if (m.nRows < 2) {
        fprintf(stderr, "there is no penultimate row");
        exit(1);
    }

    int col[m.nRows];
    position min = getLeftMin(m);

    for (int i = 0; i < m.nRows; i++)
        col[i] = m.values[i][min.colIndex];

    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

void test_swapPenultimateRow1() {
    int a[] = {7, 2, 3,
               3, 5, 7,
               2, 4, 3};
    matrix m1 = createMatrixFromArray(a, 3, 3);
    swapPenultimateRow(m1);

    int b[] = {7, 2, 3,
               7, 3, 2,
               2, 4, 3};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow2() {
    int a[] = {7, 2,
               -1, 5};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    swapPenultimateRow(m1);

    int b[] = {7, -1,
               -1, 5};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow1();
    test_swapPenultimateRow2();
}

//----------------task 13---------
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            count++;

    return count;
}

void test_countNonDescendingRowsMatrices1() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 9,
                    1, 0,

                    2, 4,
                    4, 4,

                    7, 4,
                    3, 3,

                    1, 9,
                    5, 8
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices2() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,

                    8, 8, 22,

                    -4, 0, 7,

                    1, -8, 3,
            },
            4, 1, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 3);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices3() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,

                    1,

                    -1,

                    1
            },
            4, 1, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices1();
    test_countNonDescendingRowsMatrices2();
    test_countNonDescendingRowsMatrices3();
}

//------------------task 14 ---------------

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count++;

    return count;
}

int countZeroRows(matrix m) {
    int zeroRows = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            zeroRows++;

    return zeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int zeroRowsCount[nMatrix];
    for (int k = 0; k < nMatrix; k++)
        zeroRowsCount[k] = countZeroRows(ms[k]);

    int maxZeroRows = getMax(zeroRowsCount, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (zeroRowsCount[i] == maxZeroRows)
            outputMatrix(ms[i]);
}

void test_countZeroRows1() {
    int a[] = {0, 0,
               4, 0,
               0, 0};
    matrix m = createMatrixFromArray(a, 3, 2);

    assert(countZeroRows(m) == 2);
}

void test_countZeroRows2() {
    int a[] = {5, 1,
               4, 7,
               9, 10};
    matrix m = createMatrixFromArray(a, 3, 2);

    assert(countZeroRows(m) == 0);
}

void test_countZeroRows() {
    test_countZeroRows1();
    test_countZeroRows2();
}

//------------------task 15-----------

int getMatrixNorm(matrix m) {
    int norm = abs(m.values[0][0]);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) > norm)
                norm = abs(m.values[i][j]);

    return norm;
}

void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int norms[nMatrix];

    for (int i = 0; i < nMatrix; i++)
        norms[i] = getMatrixNorm(ms[i]);

    int min = getMin(norms, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (norms[i] == min)
            outputMatrix(ms[i]);
}

void test_getMatrixNorm1() {
    int a[] = {5, -6,
               8, -20};
    matrix m = createMatrixFromArray(a, 2, 2);

    assert(getMatrixNorm(m) == 20);
}

void test_getMatrixNorm2() {
    int a[] = {-5};
    matrix m = createMatrixFromArray(a, 1, 1);

    assert(getMatrixNorm(m) == 5);
}

void test_getMatrixNorm3() {
    int a[] = {11, -45, 15};
    matrix m = createMatrixFromArray(a, 1, 3);

    assert(getMatrixNorm(m) == 45);
}

void test_getMatrixNorm() {
    test_getMatrixNorm1();
    test_getMatrixNorm2();
    test_getMatrixNorm3();
}

void test() {
    test_swapRowsWithMinAndMaxEl();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_getLeftMin();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_getMatrixNorm();

    printf("everything is ok\n");
}

int main() {
    test();
}