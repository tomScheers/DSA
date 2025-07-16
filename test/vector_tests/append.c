#include "vector.h"
#include "unity.h"
#include "test_vector.h"

void test_vector_append(void) {
  Vector *vector = NULL;
  vector_init(&vector, sizeof(int), TYPE_INT, NULL, NULL);
  int x = 10;
  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_append(vector, &x, sizeof(x)));

  int y;
  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_get(vector, 0, &y));

  TEST_ASSERT_EQUAL_INT(10, y);

  for (int i = 1; i <= VECTOR_START_CAP; ++i) {
    int value = i;
    vector_append(vector, &value, sizeof(x));
  }

  TEST_ASSERT_EQUAL_size_t(VECTOR_START_CAP * 2, vector->capacity);

  for (size_t i = 1; i < vector->size - 1; ++i) {
    int z;
    vector_get(vector, i, &z);
    TEST_ASSERT_EQUAL_INT(i, z);
  }

  long z = 10;

  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_VAL_SIZE_INCOMPATIBLE, vector_append(vector, &z, sizeof(z)));
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_DOES_NOT_EXIST, vector_append(NULL, &y, sizeof(y)));

  vector_free(vector);
}
