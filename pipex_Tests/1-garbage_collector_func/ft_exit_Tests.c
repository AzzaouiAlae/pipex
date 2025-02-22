#include "../Tests.h"

void ft_exit_simple_test1()
{
    //arrange
    is_pass_exit(0);

    //act
    ft_exit(0);    
    
    //asert
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));
}
void ft_exit_simple_test2()
{
    //arrange
    is_pass_exit(0);
    void *ptr = ft_calloc(1,1);
    ptr = ft_calloc(1,1);
    ptr = ft_calloc(1,1);
    ptr = ft_calloc(1,1);
    ptr = ft_calloc(1,1);
    ptr = ft_calloc(1,1);

    //act
    ft_exit(0);    
    
    //asert
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));
}

void ft_exit_Tests()
{
    RUN_TEST(ft_exit_simple_test1);
    RUN_TEST(ft_exit_simple_test2);
}
