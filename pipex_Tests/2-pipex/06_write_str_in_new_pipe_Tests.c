#include "../Tests.h"

void write_str_in_new_pipe_simple_test1()
{
    //arrange
    char *str = "Hello this is a tessssst";
    char result[25];
    t_pipe *p;

    //act
    write_str_in_new_pipe(str);
    p = current_pipe();
    read(p->fd_read, result, 24);

    //asert
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, str, result, 24);
}

void write_str_in_new_pipe_Tests()
{
    RUN_TEST(write_str_in_new_pipe_simple_test1);
}
