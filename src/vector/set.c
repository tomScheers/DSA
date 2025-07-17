#include "vector.h"

#include <stdio.h>
#include <string.h>

StatusCode vector_set(Vector *vector, size_t index, const void *value, size_t val_size) {
  if (!vector || !vector->data)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;

  if (index >= vector->size) {
    fprintf(stderr, "Out of bounds read, %zu > %zu\n", index, vector->size - 1); // Subtract one for base 0
    return DS_ERR_VECTOR_OUT_OF_BOUNDS_WRITE;
  }

  if (val_size != vector->elem_size)
    return DS_ERR_VECTOR_VAL_SIZE_INCOMPATIBLE;

  void *target = (char *)vector->data + index * vector->elem_size;
  printf("From: ");
  vector->print_fn(target);
  printf("To: ");
  vector->print_fn((void*)value);
  memcpy(target, value, val_size);

  return DS_SUCCESS;
}
