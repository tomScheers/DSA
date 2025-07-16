#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#include "error.h"

#define VECTOR_START_CAP 32

typedef void (*free_fn)(void *ptr);
typedef void (*print_fn)(void *ptr);

typedef enum {
  TYPE_UNKNOWN = 0,

  // Primitive integral types
  TYPE_BOOL,
  TYPE_CHAR,
  TYPE_SIGNED_CHAR,
  TYPE_UNSIGNED_CHAR,
  TYPE_SHORT,
  TYPE_UNSIGNED_SHORT,
  TYPE_INT,
  TYPE_UNSIGNED_INT,
  TYPE_LONG,
  TYPE_UNSIGNED_LONG,
  TYPE_LONGLONG,
  TYPE_UNSIGNED_LONGLONG,

  // Floating point types
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_LONG_DOUBLE,

  // Pointers
  TYPE_POINTER, // Generic non-string pointer (e.g., int*, struct*)

  // Structs and user-defined
  TYPE_STRUCT,
  TYPE_ARRAY,
  TYPE_UNION,
  TYPE_STRING,

  // Catch-all
  TYPE_NON_PRIMITIVE
} TypeToken;

typedef struct {
  void *data;
  size_t elem_size;
  TypeToken data_type;
  size_t capacity;
  size_t size;
  free_fn destructor; // Needed in case the members on data or allocated
  print_fn print_fn; // Needed in case someone uses a non-primitive (AKA structs, arrays, unions, etc) and wants to print them to the stdout
} Vector;

// Constructor function
StatusCode vector_init(Vector **vector, size_t elem_size, TypeToken type,
                       free_fn destructor, print_fn print_fn);

// Basic operations
StatusCode vector_append(Vector *vector, const void *value, size_t val_size);
StatusCode vector_get(const Vector *vector, size_t index, void *res);
StatusCode vector_set(Vector *vector, size_t index, const void *value,
                      size_t val_size);
StatusCode vector_delete(Vector *vector, size_t index); // Delete value at index
StatusCode vector_free(Vector *vector);
StatusCode vector_resize(Vector *vector, size_t new_capacity);

// Utilities
StatusCode vector_print(const Vector *vector);

// Algorithms
StatusCode vector_sort(Vector *vector);
ssize_t
vector_find(Vector *vector,
            const void *value); // Gets the first index where value is found
StatusCode vector_eliminate(
    Vector *vector,
    const void *value); // Eliminates every instance of the value in the vector

#endif
