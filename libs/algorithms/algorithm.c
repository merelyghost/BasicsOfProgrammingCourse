#include "algorithm.h"

void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

void selectionSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos], sizeof(int));
    }
}

void insertionSort(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j], sizeof(int));
}

void combSort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; i++, j++)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
    }
}

void shellSort(int *a, size_t size) {
    for (size_t step = size / 2; step > 0; step /= 2)
        for (size_t i = step; i < size; i++) {
            int tmp = a[i];
            size_t j;
            for (j = i; j >= step; j -= step) {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
}

int cmp_int(const void *a, const void *b) {
    return *(const int *) a - *(const int *) b;
}

int cmp_intReverse(const void *a, const void *b) {
    return *(const int *) b - *(const int *) a;
}


long long selectionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex], sizeof(int));
    }

    return nComps;
}

long long insertionSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 1; i < size && ++nComps; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && ++nComps && a[j - 1] > t && ++nComps) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
    return nComps;
}

long long bubbleSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; i < size - 1 && ++nComps; i++)
        for (size_t j = size - 1; j > i && ++nComps; j--)
            if (a[j - 1] > a[j] && ++nComps)
                swap(&a[j - 1], &a[j], sizeof(int));

    return nComps;
}

long long combSortNComp(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    long long nComps = 0;
    while (step > 1 && ++nComps || swapped && ++nComps) {
        if (step > 1 && ++nComps)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size && ++nComps; ++i, ++j)
            if (a[i] > a[j] && ++nComps) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
    }
    return nComps;
}

long long shellSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t step = size / 2; step > 0 && ++nComps; step /= 2)
        for (size_t i = step; i < size && ++nComps; i++) {
            int tmp = a[i];
            size_t j;
            for (j = i; j >= step && ++nComps; j -= step) {
                if (tmp < a[j - step] && ++nComps)
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
    return nComps;
}