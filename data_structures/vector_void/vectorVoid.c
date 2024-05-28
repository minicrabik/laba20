#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <memory.h>
#include "vector_void.h"

vectorVoid createVectorV(size_t n, size_t base_type_size) {
    void* data = malloc(n * base_type_size);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {data,0,n, base_type_size};
}
void reserveV(vectorVoid *v, size_t new_capacity) {
    if (new_capacity != 0) {
        void* data = realloc(v->data, v->base_type_size * new_capacity);
        if (data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = data;
        v->capacity = new_capacity;
        if (v->size > new_capacity)
            v->size = new_capacity;
    } else {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
}
void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}
void clearV(vectorVoid *v) {
    v->size = 0;
}
void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->base_type_size = 0;
}
bool isEmptyV(vectorVoid v) {
    return v.size == 0;
}
bool isFullV(vectorVoid v) {
    return v.size == v.capacity;
}
void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->base_type_size;
    memcpy(destination, source, v->base_type_size);
}
void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->capacity) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }
    char *address_element = (char *) v->data + index * v->base_type_size;
    memcpy(address_element, source, v->base_type_size);
}
void popBackV(vectorVoid *v) {
    if (isEmptyV(*v)) {
        fprintf(stderr, "Zero length");
        exit(1);
    }
    v->size--;
    if (v->size < v->capacity / 4)
        reserveV(v, v->capacity / 2);
}
void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(*v)) {
        size_t new_capacity;
        if (v->capacity == 0)
            new_capacity = 1;
        else
            new_capacity = v->capacity * 2;
        reserveV(v, new_capacity);
    }
    setVectorValueV(v, v->size, source);
    v->size++;
}
