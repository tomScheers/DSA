#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StatusCode vector_append(Vector *vector, const void *value, size_t val_size) {
  if (!vector)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;

  if (val_size != vector->elem_size) {
    printf("Expected %zu, got %lu\n", vector->elem_size, val_size);
    return DS_ERR_VECTOR_VAL_SIZE_INCOMPATIBLE;
  }

  if (vector->size == vector->capacity) {
    vector->capacity *= 2;
    void *tmp = realloc(vector->data, vector->capacity * vector->elem_size);
    if (tmp == NULL) {
      vector_free(vector);
      return DS_ERR_MALLOC_FAULT;
    }
    vector->data = tmp;
  }
  memcpy((char *)vector->data + vector->size * vector->elem_size, value,
         vector->elem_size);
  vector->size++;
  return DS_SUCCESS;
}
