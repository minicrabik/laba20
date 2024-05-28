#include <stdio.h>
#include <malloc.h>

#include "vector.h"

vector createVector(size_t n) {
    int *data = malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data,0,n};
}

void reserve(vector *v, size_t new_capacity) {
    if (new_capacity > 0) {
        int *data = realloc(v->data, sizeof(int) * new_capacity);
        if (data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = data;
        v->capacity = new_capacity;
        if (v->size > new_capacity)
            v->size = new_capacity;
    } else
        deleteVector(v);
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector v) {
    return v.size == 0;
}

bool isFull(vector v) {
    return v.size == v.capacity;
}

int getVectorValue(vector v, size_t i) {
    return v.data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(*v)) {
        size_t new_capacity;
        if (v->capacity == 0)
            new_capacity = 1;
        else
            new_capacity = v->capacity * 2;
        reserve(v, new_capacity);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Zero length");
        exit(1);
    }
    v->size--;
    if (v->size < v->capacity / 4)
        reserve(v, v->capacity / 2);
}

int* atVector(vector *v, size_t index) {
    if (index >= v->capacity) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }
    return &v->data[index];
}

int* back(vector *v) {
    if (isEmpty(*v)) {
        fprintf(stderr, "Zero length");
        exit(1);
    }
    return &v->data[v->size - 1];
}

int* front(vector *v) {
    if (isEmpty(*v)) {
        fprintf(stderr, "Zero length");
        exit(1);
    }
    return &v->data[0];
}
