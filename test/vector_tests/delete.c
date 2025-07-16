#include "vector.h"
#include "unity.h"
#include "test_vector.h"

void test_vector_delete(void) {
  Vector *vector = NULL;
  vector_init(&vector, sizeof(int), TYPE_INT, NULL, NULL);
  for (size_t i = 0; i < VECTOR_START_CAP; ++i) {
    int value = i;
    vector_append(vector, &value, sizeof(value));
  }
  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_delete(vector, 0));
  TEST_ASSERT_EQUAL_INT(VECTOR_START_CAP - 1, vector->size);
  int first_index;
  vector_get(vector, 0, &first_index);
  TEST_ASSERT_EQUAL_INT(1, first_index);

  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_DOES_NOT_EXIST, vector_delete(NULL, 0));
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_OUT_OF_BOUNDS_WRITE, vector_delete(vector, vector->size));
  vector_free(vector);
}
