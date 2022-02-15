#include "matrix.h"

void checkIndexOutOfRangeError(size_t size, size_t index) {
    if (index >= size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        inputArray(m.values[i], m.nCols);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        outputArray(m.values[i], m.nCols);
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    checkIndexOutOfRangeError(m.nRows, i1);
    checkIndexOutOfRangeError(m.nRows, i2);

    swap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    checkIndexOutOfRangeError(m.nCols, j1);
    checkIndexOutOfRangeError(m.nCols, j2);

    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int resultsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        resultsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int t = resultsCriteria[i];
        int j = i;
        while (j > 0 && resultsCriteria[j - 1] > t) {
            resultsCriteria[j] = resultsCriteria[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resultsCriteria[j] = t;
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int resultsCriteria[m.nCols];
    for (int i = 0; i < m.nCols; i++) {
        int col[m.nRows];
        for (int j = 0; j < m.nRows; j++)
            col[j] = m.values[j][i];
        resultsCriteria[i] = criteria(col, m.nRows);
    }

    for (int i = 1; i < m.nCols; i++) {
        int t = resultsCriteria[i];
        int j = i;
        while (j > 0 && resultsCriteria[j - 1] > t) {
            resultsCriteria[j] = resultsCriteria[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        resultsCriteria[j] = t;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    bool isEqual = (m1.nRows == m2.nRows && m1.nCols == m2.nCols) ? true : false;

    for (int i = 0; i < m1.nRows && isEqual; i++) {
        for (int j = 0; j < m1.nCols && isEqual; j++) {
            if (m1.values[i][j] != m2.values[i][j])
                isEqual = false;
        }
    }
    return isEqual;
}

bool isEMatrix(matrix m) {
    bool isEMatrix = isSquareMatrix(m) ? true : false;

    for (int i = 0; i < m.nRows && isEMatrix; i++) {
        for (int j = 0; j < m.nCols && isEMatrix; j++) {
            if (i == j && m.values[i][i] != 1 || i != j && m.values[i][j] != 0)
                isEMatrix = false;
        }
    }
    return isEMatrix;
}

bool isSymmetricMatrix(matrix m) {
    bool isSymmetric = isSquareMatrix(m) ? true : false;

    for (int i = 0; i < m.nRows && isSymmetric; i++) {
        for (int j = 0; j < m.nCols && isSymmetric; j++) {
            if (i != j && m.values[i][j] != m.values[j][i])
                isSymmetric = false;
        }
    }
    return isSymmetric;
}

void checkSquareMError(matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "Matrix is not square");
        exit(1);
    }
}

void transposeSquareMatrix(matrix m) {
    checkSquareMError(m);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            swap(&m.values[i][j], &m.values[j][i], sizeof(int));
        }
    }
}

position getMinValuePos(matrix m) {
    int min = m.values[0][0];
    position minPos = {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }

    return minPos;
}

position getMaxValuePos(matrix m) {
    int max = m.values[0][0];
    position maxPos = {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                maxPos.rowIndex = i;
                maxPos.colIndex = j;
            }

    return maxPos;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}