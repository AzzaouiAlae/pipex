#include "../Tests.h"

void find_str_start_with_simple_test1()
{
    //arrange
    char *result;
    char *input[] = {"hello", "", 0};
    
    //act
    result = find_str_start_with(input, "He");

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void find_str_start_with_simple_test2()
{
    //arrange
    char *result;
    char *input[] = {"Hello", "", 0};
    
    //act
    result = find_str_start_with(input, "He");

    //asert
    TEST_ASSERT_EQUAL_INT64(input[0], result);
}
void find_str_start_with_simple_test3()
{
    //arrange
    char *result;
    char *input[] = {"", "", "Hello", 0};
    
    //act
    result = find_str_start_with(input, "He");

    //asert
    TEST_ASSERT_EQUAL_INT64(input[2], result);
}
void find_str_start_with_simple_test4()
{
    //arrange
    char *result;
    char **input = 0;
    
    //act
    result = find_str_start_with(input, "He");

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}
void find_str_start_with_simple_test5()
{
    //arrange
    char *result;
    char *input[] = {"", "", "Hello", 0};
    
    //act
    result = find_str_start_with(input, 0);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void find_str_start_with_tests()
{
    RUN_TEST(find_str_start_with_simple_test1);
    RUN_TEST(find_str_start_with_simple_test2);
    RUN_TEST(find_str_start_with_simple_test3);
    RUN_TEST(find_str_start_with_simple_test4);
    RUN_TEST(find_str_start_with_simple_test5);
}