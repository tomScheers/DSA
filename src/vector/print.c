#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

StatusCode vector_print(const Vector *vector) {
  for (size_t i = 0; i < vector->size; ++i) {
    if (vector->print_fn != NULL) {
      void* res;
      vector_get(vector, i, &res);
      vector->print_fn(res);
      continue;
    }
    void *res = malloc(vector->elem_size);
    vector_get(vector, i, res);
    switch (vector->data_type) {
      case TYPE_INT:
        printf("%d", *(int*)res);
        break;
      case TYPE_BOOL:
        if (*(bool*)res) {
          printf("true");
        } else {
          printf("false");
        }
        break;
      case TYPE_CHAR:
        printf("%c", *(char*)res);
        break;
      case TYPE_DOUBLE:
        printf("%lf", *(double*)res);
        break;
      case TYPE_LONG:
        printf("%ld", *(long*)res);
        break;
      case TYPE_SHORT:
        printf("%hd", *(short*)res);
        break;
      case TYPE_FLOAT:
        printf("%f", *(float*)res);
        break;
      case TYPE_LONG_DOUBLE:
        printf("%Lf", *(long double*)res);
        break;
      case TYPE_LONGLONG:
        printf("%lld", *(long long*)res);
        break;
      case TYPE_UNSIGNED_INT:
        printf("%u", *(unsigned int*)res);
        break;
      case TYPE_UNSIGNED_CHAR:
        printf("%uc", *(unsigned char*)res);
        break;
      case TYPE_UNSIGNED_LONG:
        printf("%luld", *(unsigned long*)res);
        break;
      case TYPE_UNSIGNED_LONGLONG:
        printf("%llulld", *(unsigned long long*)res);
        break;
      case TYPE_UNSIGNED_SHORT:
        printf("%uhd", *(unsigned short*)res);
        break;
      case TYPE_STRING:
        printf("%s", (char*)res);
        break;
      default:
        printf("Type not supported, please pass down a print_fn to the constructor if it is not a primitive.\n");
        break;
    }
    if (i + 1 != vector->size) {
      printf(", ");
    }
    free(res);
  }
  printf("\n");
  return DS_SUCCESS;
}
