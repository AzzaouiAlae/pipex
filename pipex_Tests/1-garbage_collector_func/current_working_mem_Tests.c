#include "../Tests.h"

void current_working_mem_simple_test1()
{
    //arrange
    char str[10];

    //act
    void *result = current_working_mem(str, 0);

    //asert
    TEST_ASSERT_EQUAL_INT64(str, result);
}

void current_working_mem_simple_test2()
{
    //arrange
    char str[10];

    //act
    current_working_mem(str, 0);
    void *result = current_working_mem(0, 0);

    //asert
    TEST_ASSERT_EQUAL_INT64(str, result);
}

void current_working_mem_simple_test3()
{
    //arrange
    char str[10];

    //act
    current_working_mem(str, 0);
    void *result = current_working_mem(0, 1);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void current_working_mem_tests()
{
    RUN_TEST(current_working_mem_simple_test1);
    RUN_TEST(current_working_mem_simple_test2);
    RUN_TEST(current_working_mem_simple_test3);
}