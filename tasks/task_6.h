//
// Created by User on 28.05.2024.
//

#ifndef LABA20_TASK_6_H
#define LABA20_TASK_6_H

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ASCII_SHIFT 48


void generate_nums(const char* filename) {
    int num[] = {1,2,3,4,5,6,7,8,9};


    FILE* file = fopen(filename, "r");

    char res[10] = "";
    char s[10] = "";
    fscanf(file, "%s", s);

    fclose(file);


    unsigned int len_s = strlen(s);

    char* rec_ptr = res;
    char* read_ptr = s;
    unsigned int i_ind = 0;
    unsigned int d_ind = len_s;


    while (i_ind != d_ind) {
        if (*read_ptr == 'I') {
            *rec_ptr = (char) (num[i_ind] + ASCII_SHIFT);
            i_ind++;
        } else {
            *rec_ptr = (char) (num[d_ind] + ASCII_SHIFT);
            d_ind--;
        }

        read_ptr++;
        rec_ptr++;
    }

    *rec_ptr = (char) (num[i_ind] + ASCII_SHIFT);


    file = fopen(filename, "w");

    fprintf(file, "%s", res);

    fclose(file);
}


void test_generate_nums_1_empty_file() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_6_test_1.txt";

    FILE* file = fopen(filename, "w");
    fclose(file);


    generate_nums(filename);


    file = fopen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 1);
}


void test_generate_nums_2_unit_length() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_6_test_2.txt";

    FILE* file = fopen(filename, "w");

    fprintf(file, "I");

    fclose(file);


    generate_nums(filename);


    file = fopen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 12);
}


void test_generate_nums_3_average_length() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_6_test_3.txt";

    FILE* file = fopen(filename, "w");

    fprintf(file, "IIID");

    fclose(file);


    generate_nums(filename);


    file = fopen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 12354);
}


void test_generate_nums_4_max_length() {
    const char filename[] = "C:\\Users\\Desktop\\laba_op_20\\task_6_test_4.txt";

    FILE* file = fopen(filename, "w");

    fprintf(file, "IIIIIIII");

    fclose(file);


    generate_nums(filename);


    file = fopen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 123456789);
}


void test_generate_nums() {
    test_generate_nums_1_empty_file();
    test_generate_nums_2_unit_length();
    test_generate_nums_3_average_length();
    test_generate_nums_4_max_length();
}

#endif //LABA20_TASK_6_H
