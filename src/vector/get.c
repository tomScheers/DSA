#include "vector.h"

#include <string.h>

StatusCode vector_get(const Vector *vector, size_t index, void *res) {
  if (!vector)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;

  if (index > vector->size || index < 0)
    return DS_ERR_VECTOR_OUT_OF_BOUNDS_READ;

  void *src = (char *)vector->data + index * vector->elem_size;
  vector->print_fn(src);
  memcpy(res, src, vector->elem_size);
  return DS_SUCCESS;
}
