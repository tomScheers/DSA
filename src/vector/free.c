#include "vector.h"

#include <stdlib.h>

StatusCode vector_free(Vector *vector) {
  if (vector == NULL)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;

  if (vector->destructor != NULL) {
    for (size_t i = 0; i < vector->size; ++i) {
      void* val = NULL;
      vector_get(vector, i, val);
      vector->destructor(val);
    }
  }
  free(vector->data);
  free(vector);
  return DS_SUCCESS;
}
