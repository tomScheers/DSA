#include "vector.h"

#include <string.h>


StatusCode vector_delete(Vector *vector, size_t index) {
  if (!vector || !vector->data)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;
  
  if(index >= vector->size)
    return DS_ERR_VECTOR_OUT_OF_BOUNDS_WRITE;

  // Move each item in the vector one to the left
  for (size_t i = 0; i < vector->size; ++i) {
    void *target = (char *)vector->data + i * vector->elem_size;
    void *src = (char *)vector->data + (i + 1) * vector->elem_size;
    memcpy(target, src, vector->elem_size);
  }

  if (vector->destructor != NULL) {
    void* destructor_val = NULL;
    vector_get(vector, vector->size - 1, destructor_val);
    vector->destructor(destructor_val);
  }

  --vector->size;
  return DS_SUCCESS;
}
