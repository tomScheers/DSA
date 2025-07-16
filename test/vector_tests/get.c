#include "unity.h"
#include "test_vector.h"
#include "vector.h"

void test_vector_get(void) {
  Vector *vector = NULL;
  vector_init(&vector, sizeof(int), TYPE_INT, NULL, NULL);
  for (size_t i = 0; i < vector->capacity; ++i) {
    int value = i;
    vector_append(vector, &value, sizeof(value));
    TEST_ASSERT_EQUAL_INT(i, value);
  }

  void *x = NULL;
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_OUT_OF_BOUNDS_READ,
                    vector_get(vector, vector->size + 1, x));
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_OUT_OF_BOUNDS_READ,
                    vector_get(vector, -1, x));

  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_DOES_NOT_EXIST, vector_get(NULL, 1, x));
  vector_free(vector);
}
