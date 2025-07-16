#include "vector.h"

static bool is_numerical(TypeToken type);

// Use quicksort for simplicity
StatusCode vector_sort(Vector *vector) {
  if (!vector)
    return DS_ERR_VECTOR_DOES_NOT_EXIST;

  if (!is_numerical(vector->data_type))
    return DS_ERR_VECTOR_DATA_TYPE_NON_NUMERICAL;

  long long *data = vector->data;

  return DS_SUCCESS;
}

static bool is_numerical(TypeToken type) {
  switch (type) {
  case TYPE_INT:
  case TYPE_DOUBLE:
  case TYPE_FLOAT:
  case TYPE_LONG:
  case TYPE_LONGLONG:
  case TYPE_LONG_DOUBLE:
  case TYPE_SHORT:
  case TYPE_UNSIGNED_INT:
  case TYPE_UNSIGNED_LONG:
  case TYPE_UNSIGNED_SHORT:
  case TYPE_UNSIGNED_LONGLONG:
  // Char values, treated as an integer
  case TYPE_CHAR:
  case TYPE_SIGNED_CHAR:
  case TYPE_UNSIGNED_CHAR:
    return true;
  default:
    return false;
  }
}
