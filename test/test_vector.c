#include "unity.h"
#include "vector.h"
#include <stdlib.h>

void setUp() {}
void tearDown() {}

void test_vector_init(void) {
  Vector *vector = vector_init(sizeof(int));
  if (vector == NULL) {
    TEST_FAIL();
  }
  TEST_ASSERT_EQUAL(VECTOR_START_CAP, vector->capacity);
  TEST_ASSERT_EQUAL(0, vector->size);
  TEST_ASSERT_EQUAL(sizeof(int), vector->elem_size);
  vector_free(vector);
}

void test_vector_append(void) {
  Vector *vector = vector_init(sizeof(int));
  int x = 10;
  vector_append(vector, &x);

  int y = *(int*)vector_get(vector, 0);

  TEST_ASSERT_EQUAL_INT(10, y);

  for (int i = 1; i <= VECTOR_START_CAP; ++i) {
    int value = i;
    vector_append(vector, &value);
  }

  TEST_ASSERT_EQUAL_size_t(VECTOR_START_CAP * 2, vector->capacity);

  for (size_t i = 1; i < vector->size - 1; ++i) {
    void *curr_val = vector_get(vector, i);
    TEST_ASSERT_EQUAL_INT(i, *(int*)curr_val);
  }

  vector_free(vector);
}

void test_vector_get(void) {
  Vector *vector = vector_init(sizeof(int));
  for (size_t i = 0; i < vector->capacity; ++i) {
    int value = i;
    vector_append(vector, &value);
    TEST_ASSERT_EQUAL_INT(i, *(int*)vector_get(vector, i));
  }

  TEST_ASSERT_NULL(vector_get(vector, vector->size + 1));
  TEST_ASSERT_NULL(vector_get(vector, -1));
  TEST_ASSERT_NULL(vector_get(vector, 'H'));
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_vector_init);
  RUN_TEST(test_vector_append);
  //RUN_TEST(test_vector_get);
  return UNITY_END();
}
