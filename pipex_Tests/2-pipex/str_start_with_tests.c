#include "../Tests.h"

void str_start_with_simple_test1()
{
    //arrange
    int result;

    //act
    result = str_start_with(0, 0);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void str_start_with_simple_test2()
{
    //arrange
    int result;

    //act
    result = str_start_with(0, "hello");

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void str_start_with_simple_test3()
{
    //arrange
    int result;

    //act
    result = str_start_with("Hello", 0);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void str_start_with_simple_test4()
{
    //arrange
    int result;

    //act
    result = str_start_with("Hello", "He");

    //asert
    TEST_ASSERT_EQUAL_INT64(1, result);
}

void str_start_with_tests()
{
    RUN_TEST(str_start_with_simple_test1);
    RUN_TEST(str_start_with_simple_test2);
    RUN_TEST(str_start_with_simple_test3);
    RUN_TEST(str_start_with_simple_test4);
}