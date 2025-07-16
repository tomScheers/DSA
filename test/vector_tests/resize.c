#include "vector.h"
#include "test_vector.h"
#include "unity.h"

void test_vector_resize(void) {
  Vector *vector = NULL;
  vector_init(&vector, sizeof(int), TYPE_INT, NULL, NULL);
  // Append values to the vector until it's at the VECTOR_START_CAP, that way it doubles in size, so that vector->capacity == 64 and vector->size == 32
  for (size_t i = 0; i <= VECTOR_START_CAP; ++i) {
    int value = i;
    vector_append(vector, &value, sizeof(value));
  }

  vector_delete(vector, 0);
  TEST_ASSERT_EQUAL(VECTOR_START_CAP * 2, vector->capacity);
  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_resize(vector, VECTOR_START_CAP));
  TEST_ASSERT_EQUAL(VECTOR_START_CAP, vector->capacity);
  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_resize(vector, vector->capacity * 10));
  TEST_ASSERT_EQUAL(VECTOR_START_CAP * 10, vector->capacity);
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_DOES_NOT_EXIST, vector_resize(NULL, 200));
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_CAP_LESS_THAN_SIZE, vector_resize(vector, vector->size - 1));
  vector_free(vector);
}
