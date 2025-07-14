#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>

#define VECTOR_START_CAP 32

typedef struct {
  void *data;
  size_t elem_size;
  size_t capacity;
  size_t size;
} Vector;

// Constructor function
Vector *vector_init(size_t elem_size);

// Basic operations
bool vector_append(Vector *vector, const void *value);
void *vector_get(const Vector *vector,
                 size_t index); // Get value at index with bount checking
bool vector_set(Vector *vector, size_t index, const void *value);
bool vector_delete(Vector *vector, size_t index); // Delete value at index
void vector_free(Vector *vector);
bool vector_resize(Vector *vector, size_t new_capacity);

// Algorithms
bool vector_sort(Vector *vector);
ssize_t
vector_find(Vector *vector,
            const void *value); // Gets the first index where value is found
bool vector_eliminate(
    Vector *vector,
    const void *value); // Eliminates every instance of the value in the vector

#endif
