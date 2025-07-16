#include "vector.h"
#include "test_vector.h"


void test_vector_print(void) {
  Vector *vector_int = NULL;
  vector_init(&vector_int, sizeof(int), TYPE_INT, NULL, NULL);
  for (size_t i = 0; i < vector_int->capacity; ++i) {
    int value = i;
    vector_append(vector_int, &value, sizeof(value));
  }
  vector_print(vector_int);
  vector_free(vector_int);

  Vector *vector_bool = NULL;
  vector_init(&vector_bool, sizeof(bool), TYPE_BOOL, NULL, NULL);
  for (size_t i = 0; i < vector_bool->capacity; ++i) {
    bool value = i % 2 == 0;
    vector_append(vector_bool, &value, sizeof(value));
  }
  vector_print(vector_bool);
  vector_free(vector_bool);

  Vector *vector_str = NULL;
  vector_init(&vector_str, sizeof(char*), TYPE_STRING, NULL, NULL);
  for (size_t i = 0; i < vector_bool->capacity; ++i) {
    bool value = i % 2 == 0;
    if (value) {
      vector_append(vector_str, &"Tom", sizeof(char*));
    } else {
      vector_append(vector_str, &"Scheers", sizeof(char*));
    }
  }
  vector_print(vector_str);
  vector_free(vector_str);
}
