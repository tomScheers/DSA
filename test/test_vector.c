#include "vector_tests/test_vector.h"
#include "unity.h"

void setUp() {}
void tearDown() {}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_vector_init);
  RUN_TEST(test_vector_append);
  RUN_TEST(test_vector_get);
  RUN_TEST(test_vector_set);
  RUN_TEST(test_vector_delete);
  RUN_TEST(test_vector_resize);
  RUN_TEST(test_vector_print);
  return UNITY_END();
}
