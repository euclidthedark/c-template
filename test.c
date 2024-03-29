#include<stdio.h>
#include<CUnit/Basic.h>
#include<CUnit/CUnit.h>
#include"helloworld.h"

int init_suite1 () {
    printf("Starting suite\n");

    return 0;
}

int clean_suite1 () {
    printf("\nEnding suite\n");

    return 0;
}

void test_hello_world() {
    CU_ASSERT_STRING_EQUAL(hello_world(), "Hello World!");
}

int main() {
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "test_hello_world", test_hello_world)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
