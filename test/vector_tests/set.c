#include "vector.h"
#include "test_vector.h"
#include "unity.h"


void test_vector_set(void) {
  Vector *vector = NULL;
  vector_init(&vector, sizeof(int), TYPE_INT, NULL, NULL);
  for (size_t i = 0; i < vector->capacity; ++i) {
    int value = i;
    vector_append(vector, &value, sizeof(value));
  }

  printf("Hello\n");

  int val = 15;
  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_set(vector, 0, &val, sizeof(val)));
  printf("TEST\n");
  int res;
  vector_get(vector, 0, &res);
  TEST_ASSERT_EQUAL(15, res);

  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_DOES_NOT_EXIST, vector_set(NULL, 0, &val, sizeof(val)));
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_OUT_OF_BOUNDS_WRITE, vector_set(vector, vector->size, &val, sizeof(val)));
  
  long int val_2 = 21;
  TEST_ASSERT_EQUAL(DS_ERR_VECTOR_VAL_SIZE_INCOMPATIBLE, vector_set(vector, 1, &val_2, sizeof(val_2)));
  vector_free(vector);
}
