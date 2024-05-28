#ifndef LABA19_VECTORVOID_H
#define LABA19_VECTORVOID_H

#ifndef UNTITLED7_VECTOR_VOID_H
#define UNTITLED7_VECTOR_VOID_H

#ifndef UNTITLED6_VECTOR_VOID_H
#define UNTITLED6_VECTOR_VOID_H
#include <limits.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void* data;
    size_t size;
    size_t capacity;
    size_t base_type_size;
} vectorVoid;

// возвращает структуру вектор размера n для элементов с размером base_type_size
vectorVoid createVectorV(size_t n, size_t base_type_size);

// изменяет количество памяти вектора v на newCapacity
void reserveV(vectorVoid *v, size_t new_capacity);

// очищает память выделенную под неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// очищает вектор v от элементов
void clearV(vectorVoid *v);

// освобождает память выделенную под вектор v
void deleteVectorV(vectorVoid *v);

// возвращает true, если vector v пуст
// иначе false
bool isEmptyV(vectorVoid v);

// возвращает true, если vector v полон
// иначе false
bool isFullV(vectorVoid v);

// записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент вектора v
void popBackV(vectorVoid *v);

// добавляет в конец вектора v значение, расположенное по адресу source
void pushBackV(vectorVoid *v, void *source);

#endif //UNTITLED6_VECTOR_VOID_H

#endif //UNTITLED7_VECTOR_VOID_H

#endif //LABA19_VECTORVOID_H
