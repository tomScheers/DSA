#include "vector.h"

#include <stdlib.h>
#include <string.h>


Vector *vector_init(size_t elem_size) {
  Vector *vector = malloc(sizeof(Vector));
  if (vector == NULL) {
    return NULL;
  }

  vector->capacity = VECTOR_START_CAP;
  vector->elem_size = elem_size;
  vector->size = 0;
  vector->data = malloc(vector->capacity * vector->elem_size);
  if (vector->data == NULL) {
    free(vector);
    return NULL;
  }
  return vector;
}

// Basic operations
StatusCode vector_append(Vector *vector, const void *value) {
  if (vector->size == vector->capacity) {
    vector->capacity *= 2;
    void *tmp = realloc(vector->data, vector->capacity * vector->elem_size);
    if (tmp == NULL) {
      vector_free(vector);
      return MALLOC_ERROR;
    }
    vector->data = tmp;
  }
  memcpy((char *)vector->data + vector->size * vector->elem_size, value,
         vector->elem_size);
  vector->size++;
  return true;
}

void *vector_get(const Vector *vector, size_t index) {
  if (index >= vector->size)
    return (void*)OUT_OF_BOUNDS_READ;

  return (char *)vector->data + index * vector->elem_size;
}

StatusCode vector_set(Vector *vector, size_t index, const void *value) {
  if (!vector)
    return VECTOR_DOES_NOT_EXIST;
  return true;
}
StatusCode vector_delete(Vector *vector, size_t index); // Delete value at index

void vector_free(Vector *vector) {
  if (!vector)
    return;
  free(vector->data);
  free(vector);
}
StatusCode vector_resize(Vector *vector, size_t new_capacity);

// Algorithms
StatusCode vector_sort(Vector *vector);
ssize_t
vector_find(Vector *vector,
            const void *value); // Gets the first index where value is found
StatusCode vector_eliminate(
    Vector *vector,
    const void *value); // Eliminates every instance of the value in the vector
