#include "../Tests.h"

void bzero_simple_test1()
{
    //arrange
    char str[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 0};

    //act
    ft_bzero(str, 10);
    
    //asert
    TEST_ASSERT_EACH_EQUAL_CHAR(0, str, 10);
}
void bzero_simple_test2()
{
    //arrange
    char *str = NULL;

    //act
    ft_bzero(str, 10);
    
    //asert
    TEST_ASSERT_EQUAL_INT64(0, str);
}
void bzero_simple_test3()
{
    //arrange
    char str[10] = {'0', '0', '0'};

    //act
    ft_bzero(str, 0);
    
    //asert
    TEST_ASSERT_EACH_EQUAL_CHAR('0', str, 3);
}

void bzero_tests()
{
    RUN_TEST(bzero_simple_test1);
    RUN_TEST(bzero_simple_test2);
    RUN_TEST(bzero_simple_test3);
}