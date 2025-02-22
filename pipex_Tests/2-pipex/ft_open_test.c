#include "../Tests.h"

void ft_open_simple_test1()
{
    //arrange
    int fd;
    char str2[15];

    //act
    fd = ft_open("file2.txt", O_RDONLY, 0666);
    if (fd)
    {
        int i = read(fd, str2, 15);
        str2[i] = '\0';
    }      
    
    //asert
    TEST_ASSERT_EQUAL_CHAR_ARRAY("this is a file", str2, 15);
}
void ft_open_simple_test2()
{
    //arrange
    char *str = calloc(1, 10);
    int fd;
    char str2[15];
    is_pass_exit(0);

    //act
    t_mem_list **list = ft_mem_list();
    (*list) = calloc(1, sizeof(t_mem_list));
    (*list)->mem = str;

    t_mem_list **list2 = ft_mem_list();
    void *result = (*list)->mem;

    //asert
    TEST_ASSERT_EQUAL_INT64(str, result);

    //act
    fd = ft_open("file20.txt", O_RDONLY, 0666);

    //asert
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));
}

void ft_open_test()
{
    RUN_TEST(ft_open_simple_test1);
    RUN_TEST(ft_open_simple_test2);
}