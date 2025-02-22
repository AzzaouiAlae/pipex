#include "../Tests.h"

void ft_free_simple_test1()
{
    //arrange
    char *str[5];
    
    str[0] = ft_calloc(1, 1);
    str[1] = ft_calloc(1, 1);
    str[2] = ft_calloc(1, 1);
    str[3] = ft_calloc(1, 1);
    str[4] = ft_calloc(1, 1);

    //act
    
    ft_free(str[0]);
    ft_free(str[2]);
    ft_free(str[4]);
    
    //asert
    ft_free_all();
}

void ft_free_all_Tests()
{
    RUN_TEST(ft_free_simple_test1);
}
