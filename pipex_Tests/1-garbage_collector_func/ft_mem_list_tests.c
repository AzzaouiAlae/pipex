#include "../Tests.h"

void ft_mem_list_tests_simple_test1()
{
    //arrange
    char str[10];

    //act
    t_mem_list **list = ft_mem_list();
    (*list) = malloc(sizeof(t_mem_list));
    (*list)->mem = str;

    t_mem_list **list2 = ft_mem_list();
    void *result = (*list)->mem;
    //asert
    TEST_ASSERT_EQUAL_INT64(str, result);

    free((*list));
    (*list) = NULL;
}

void ft_mem_list_tests()
{
    RUN_TEST(ft_mem_list_tests_simple_test1);
}
