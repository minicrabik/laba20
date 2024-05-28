#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>
#include "matrix.h"

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}


matrix getMemMatrix(int n_rows, int n_cols) {
    int **values = (int **) malloc(sizeof(int*) * n_rows);
    for (int i = 0; i < n_rows; i++)
        values[i] = (int *) malloc(sizeof(int) * n_cols);
    return (matrix){values, n_rows, n_cols};
}

matrix *getMemArrayOfMatrices(int n_matrices,
                              int n_rows, int n_cols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * n_matrices);
    for (int i = 0; i < n_matrices; i++)
        ms[i] = getMemMatrix(n_rows, n_cols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->n_rows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = NULL;
    m->n_rows = 0;
    m->n_cols = 0;
}

void freeMemMatrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        freeMemMatrix(ms + i);

    free(ms->values);
    ms->values = NULL;
    ms->n_rows = 0;
    ms->n_cols = 0;
}

void inputMatrix(matrix  *m) {
    for (int i = 0; i < m->n_rows; i++) {
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->n_cols; j++)
            scanf("%d", &m->values[i][j]);
    }
}
void inputMatrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++) {
        printf("input %lld matrix\n", i + 1);
        inputMatrix(ms + i);
        printf("\n");
    }
}


void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.n_rows; i++) {
        for (size_t j = 0; j < m.n_cols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}


void outputMatrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        outputMatrix(*(ms + i));
}


void swapRows(matrix* m, int i1, int i2) {
    int* temp = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = temp;
}


void swapColumns(matrix* m, int j1, int j2) {
    for (int i = 0; i < m->n_rows; i++)
        swap(&m->values[i][j1], &m->values[i][j2]);
}


void insertionSortRowsMatrixByRowCriteria(matrix* m, int (*criteria) (int*, int)) {
    int res_criteria[m->n_rows];

    for (size_t i = 0; i < m->n_rows; i++)
        res_criteria[i] = criteria(m->values[i], m->n_cols);

    int i, j, key;
    int* address_key;
    for (i = 1; i < m->n_rows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swapRows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}


void selectionSortColsMatrixByColCriteria(matrix* m, int (*criteria) (int*, int)) {
    int res_criteria[m->n_cols];

    for (size_t i = 0; i < m->n_cols; i++) {
        int temp[m->n_rows];
        for (size_t j = 0; j < m->n_rows; j++)
            temp[j] = m->values[j][i];

        res_criteria[i] = criteria(temp, m->n_rows);
    }

    int value_min_idx;
    for (int i = 0; i < m->n_cols; i++) {
        value_min_idx = i;

        for (int j = i + 1; j < m->n_cols; j++)
            if (res_criteria[j] < res_criteria[value_min_idx])
                value_min_idx = j;

        swap(&res_criteria[value_min_idx], &res_criteria[i]);
        swapColumns(m, value_min_idx, i);
    }
}

bool isSquareMatrix(matrix* m) {
    return m->n_rows == m->n_cols;
}


bool areTwoMatricesEqual(matrix* m1, matrix* m2) {
    for (size_t i = 0; i < m1->n_rows; i++)
        if (memcmp(m1->values[i], m2->values[i], m1->n_cols) != 0)
            return false;
    return true;
}

bool isEMatrix(matrix *m) {
    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = 0; j < m->n_cols; j++)
            if ((j != i && m->values[i][j] != 0) || (j == i && m->values[i][j] != 1))
                return false;
    return true;
}

bool isSymmetricMatrix(matrix *m) {
    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = i + 1; j < m->n_cols; j++)
            if (m->values[i][j] != m->values[j][i])
                return false;
    return true;
}


void transposeSquareMatrix(matrix* m) {
    if (m->n_rows != m->n_cols) {
        fprintf(stderr, "Is not square matrix");
        exit(1);
    }

    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = i + 1; j < m->n_cols; j++)
            if (i != j)
                swap(&m->values[i][j], &m->values[j][i]);
}


void transposeMatrix(matrix* m) {
    int** new_value = (int**) malloc(sizeof(int*) * m->n_cols);

    for (size_t i = 0; i < m->n_cols; i++) {
        new_value[i] = (int*) malloc(sizeof(int) * m->n_rows);

        for (size_t j = 0; j < m->n_rows; j++)
            new_value[i][j] = m->values[j][i];
    }

    for (size_t i = 0; i < m->n_rows; i++)
        free(m->values[i]);
    free(m->values);

    m->values = new_value;
    swap(&m->n_rows, &m->n_cols);
}


position getMinValuePos(matrix m) {
    int min_value = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.n_rows; i++)
        for (int j = 0; j < m.n_cols; j++)
            if (m.values[i][j] < min_value) {
                min_value = m.values[i][j];
                pos.row_index = i;
                pos.col_index = j;
            }

    return pos;
}

position getMaxValuePos(matrix m) {
    int max_value = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.n_rows; i++)
        for (int j = 0; j < m.n_cols; j++)
            if (m.values[i][j] > max_value) {
                max_value = m.values[i][j];
                pos.row_index = i;
                pos.col_index = j;
            }

    return pos;
}


matrix createMatrixFromArray(const int a[], int n_rows, int n_cols) {
    matrix m = getMemMatrix(n_rows, n_cols);

    int k = 0;
    for (int i = 0; i < n_rows; i++)
        for (int j = 0; j < n_cols; j++)
            m.values[i][j] = a[k++];

    return m;
}


matrix* createArrayOfMatrixFromArray(const int values[], size_t n_matrices, size_t n_rows, size_t n_cols) {
    matrix* ms = getMemArrayOfMatrices(n_matrices, n_rows, n_cols);

    int l = 0;
    for (size_t k = 0; k < n_matrices; k++)
        for (size_t i = 0; i < n_rows; i++)
            for (size_t j = 0; j < n_cols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}
