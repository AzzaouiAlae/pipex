#include "../Tests.h"

void all_pipes_simple_test1()
{
    //arrange
    t_pipe *p  = ft_calloc(1, sizeof(t_pipe));
    t_pipe *result;
    p->fd_read = 10;
    p->fd_write = 11;

    //act
    result = all_pipes(add, p);

    //asert
    TEST_ASSERT_EQUAL_INT64(p, result);
    TEST_ASSERT_EQUAL_INT64(p->fd_read, result->fd_read);
    TEST_ASSERT_EQUAL_INT64(p->fd_write, result->fd_write);
    ft_free_all();
}

void all_pipes_tests()
{
    RUN_TEST(all_pipes_simple_test1);
}