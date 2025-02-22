#include "../Tests.h"
#include <string.h>

void rederect_fd_to_pipe_test1()
{
    //arrange
    t_cs_list *str = cs_list_new(sizeof(char));    
    t_pipe *cur_pipe = create_pipe();
    add_pipe(cur_pipe);
    int n = 1;
    char ch;
    ft_putstr_fd("hello this is a test", cur_pipe->fd_write);
    close(cur_pipe->fd_write);
    save_std_input();
    save_std_output();

    //act
    rederect_fd_to_pipe();
    while(n)
    {
        n = read(0, &ch, 1);
        if(n)
            cs_list_add(str, (long)ch);
    }    
    dup2(std_input(-1), 0);
    dup2(std_output(-1), 1);

    //asert
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, "hello this is a test", str->contate, 21);
}

void rederect_fd_to_pipe_Tests()
{
    RUN_TEST(rederect_fd_to_pipe_test1);
}
