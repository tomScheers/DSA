#include "vector.h"

#include <stdlib.h>

StatusCode vector_init(Vector **vector, size_t elem_size, TypeToken type, free_fn destructor, print_fn print_fn) {
  if (vector != NULL)
    vector_free(*vector); // Free contents if already allocated

  *vector = malloc(sizeof(Vector));
  if (*vector == NULL)
    return DS_ERR_MALLOC_FAULT;

  (*vector)->capacity = VECTOR_START_CAP;
  (*vector)->elem_size = elem_size;
  (*vector)->size = 0;
  (*vector)->data = malloc((*vector)->capacity * (*vector)->elem_size);
  (*vector)->destructor = destructor;
  (*vector)->data_type = type ? type : TYPE_UNKNOWN;
  (*vector)->print_fn = print_fn;
  if ((*vector)->data == NULL) {
    free(*vector);
    *vector = NULL;
    return DS_ERR_MALLOC_FAULT;
  }

  return DS_SUCCESS;
}
