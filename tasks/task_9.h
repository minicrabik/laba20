//
// Created by User on 29.05.2024.
//

#ifndef LABA20_TASK_9_H
#define LABA20_TASK_9_H

#include <stdio.h>

#include "../data_structures/vector/vector.h"


void filter_nums(const char* filename, const int n) {
    FILE* file = fopen(filename, "r");

    int x;
    vector v = createVector(16);
    while (fscanf(file, "%d ", &x) == 1)
        if (x < n)
            pushBack(&v, x);

    fclose(file);


    file = fopen(filename, "w");

    for (int i = 0; i < v.size; i++) {
        x = getVectorValue(v, i);
        fprintf(file, "%d ", x);
    }

    fprintf(file, "\n");

    fclose(file);
}

#endif //LABA20_TASK_9_H
