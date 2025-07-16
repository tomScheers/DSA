#include "vector.h"

#include <stdlib.h>

StatusCode vector_resize(Vector *vector, size_t new_capacity) {
  if (!vector)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;

  if (new_capacity < vector->size)
    return DS_ERR_VECTOR_CAP_LESS_THAN_SIZE;

  vector->capacity = new_capacity;
  void* data_cp = realloc(vector->data, vector->capacity * vector->elem_size);
  if (data_cp == NULL) {
    vector_free(vector);
    return DS_ERR_MALLOC_FAULT;
  }
  vector->data = data_cp;

  return DS_SUCCESS;
}
