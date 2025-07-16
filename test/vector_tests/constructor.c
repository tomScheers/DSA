#include "test_vector.h"
#include "unity.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>

struct MyStruct {
  char *name;
  int age;
};

void print_struct(struct MyStruct *my_struct) {
  printf("%s, %d years old\n", my_struct->name, my_struct->age);
}

void free_struct(struct MyStruct *my_struct) {
  free(my_struct->name);
  free(my_struct);
}

void test_vector_init(void) {
  Vector *vector = NULL;
  vector_init(&vector, sizeof(int), TYPE_INT, NULL, NULL);
  if (vector == NULL) {
    TEST_FAIL();
  }
  TEST_ASSERT_EQUAL(VECTOR_START_CAP, vector->capacity);
  TEST_ASSERT_EQUAL(0, vector->size);
  TEST_ASSERT_EQUAL(sizeof(int), vector->elem_size);
  vector_free(vector);

  Vector *vector_struct = NULL;
  vector_init(&vector_struct, sizeof(struct MyStruct), TYPE_STRUCT,
              (print_fn)free_struct, (print_fn)print_struct);

  char* my_name = "Tom Scheers";
  for (size_t i = 0; i < vector_struct->capacity; ++i) {
    struct MyStruct *my_struct = malloc(sizeof(struct MyStruct));

    my_struct->name = malloc(sizeof(char) * strlen(my_name) + 1);
    strcpy(my_struct->name, my_name);
    my_struct->age = 15;
    vector_append(vector_struct, my_struct, sizeof(struct MyStruct));
  }
  struct MyStruct *my_struct = malloc(sizeof(struct MyStruct));
  char* second_name = "Bram Scheers";
  my_struct->name = malloc(sizeof(char) * strlen(second_name) + 1);
  strcpy(my_struct->name, second_name);
  my_struct->age = 13;

  vector_struct->print_fn(my_struct);

  TEST_ASSERT_EQUAL(DS_SUCCESS, vector_set(vector_struct, 0, my_struct, sizeof(struct MyStruct)));
  struct MyStruct *get_struct = NULL;
  vector_get(vector_struct, 0, get_struct);
  print_struct(get_struct);
  vector_print(vector_struct);
  vector_free(vector_struct);
}
