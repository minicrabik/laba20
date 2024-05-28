//
// Created by User on 28.05.2024.
//

#ifndef LABA20_TASK_1_H
#define LABA20_TASK_1_H

#include <stdio.h>
#include <assert.h>
#include "../data_structures/matrix/matrix.h"


typedef struct coord {
    int row1;
    int col1;
    int row2;
    int col2;
} coord;


void fill_matrix(const char* filename) {
    FILE* file = fopen(filename, "rb");

    int n;
    fread(&n, sizeof(int), 1, file);

    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m.values[i][j] = 0;

    coord c;
    while(fread(&c, sizeof(coord), 1, file) == 1)
        for (int i = c.row1; i <= c.row2; i++)
            for (int j = c.col1; j <= c.col2; j++)
                m.values[i][j]++;

    fclose(file);


    file = fopen(filename, "wb");

    fwrite(&n, sizeof(int), 1, file);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fwrite(&m.values[i][j], sizeof(int), 1, file);


    freeMemMatrix(&m);
    fclose(file);
}


void test_fill_matrix_1_empty_file() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_1_test_1.txt";

    FILE* file = fopen(filename, "wb");

    int n = 0;
    fwrite(&n, sizeof(int), 1, file);

    fclose(file);

    fill_matrix(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);

    fclose(file);

    assert(n == 0);
}


void test_fill_matrix_2_unit_matrix() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_1_test_2.txt";

    FILE* file = fopen(filename, "wb");

    int n = 1;
    fwrite(&n, sizeof(int), 1, file);

    coord c = {.row1=0, .col1=0, .row2=0, .col2=0};
    fwrite(&c, sizeof(coord), 1, file);

    fclose(file);

    fill_matrix(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);

    int x;
    fread(&x, sizeof(int), 1, file);

    fclose(file);

    assert(n == 1);
    assert(x == 1);
}


void test_fill_matrix_3_more_matrix_element() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_1_test_3.txt";

    FILE* file = fopen(filename, "wb");

    int n = 3;
    fwrite(&n, sizeof(int), 1, file);

    coord c1 = {.row1=1, .col1=1, .row2=2, .col2=2};
    coord c2 = {.row1=0, .col1=0, .row2=1, .col2=1};
    fwrite(&c1, sizeof(coord), 1, file);
    fwrite(&c2, sizeof(coord), 1, file);

    fclose(file);

    fill_matrix(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);

    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fread(&m.values[i][j], sizeof(int), 1, file);

    matrix check = createMatrixFromArray((int[]) {1, 1, 0,
                                                     1, 2, 1,
                                                     0, 1, 1}, 3, 3);

    assert(n == 3);
    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
    fclose(file);
}


void test_fill_matrix() {
    test_fill_matrix_1_empty_file();
    test_fill_matrix_2_unit_matrix();
    test_fill_matrix_3_more_matrix_element();
}

#endif //LABA20_TASK_1_H
