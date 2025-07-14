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
  TEST_ASSERT_EQUAL(vector->capacity, VECTOR_START_CAP);
  TEST_ASSERT_EQUAL(vector->size, 0);
  TEST_ASSERT_EQUAL(vector->elem_size, sizeof(int));
}

//void test_vector_append(void) {
//  Vector *vector = vector_init(sizeof(int));
//  int x = 10;
//  vector_append(vector, &x);
//
//  TEST_ASSERT_EQUAL(vector_get(vector, 0), 10);
//
//  for (long i = 0; i < VECTOR_START_CAP; ++i) {
//    vector_append(vector, (void *)i);
//  }
//
//  TEST_ASSERT_EQUAL(vector->capacity, VECTOR_START_CAP * 2);
//
//  for (int i = 1; i <= VECTOR_START_CAP; ++i) {
//    void *curr_val = vector_get(vector, i);
//    TEST_ASSERT_EQUAL(curr_val, i);
//  }
//}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_vector_init);
//  RUN_TEST(test_vector_append);
  return UNITY_END();
}
