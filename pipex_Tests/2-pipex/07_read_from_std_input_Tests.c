#include "../Tests.h"
#include <string.h>

void read_from_std_input_simple_test1()
{
    //arrange
    all_pipes(null, NULL);
    t_pipe *p;
    t_cs_list *str = cs_list_new(sizeof(char));
    char *str_result = "hello";
    char buff[10];
    int n = 10;   
    char *s;

    //act
    read_from_std_input("end");
    p = current_pipe();
    while(n == 10)
    {
        n = read(p->fd_read, buff, 10);
        cs_list_add_range(str, n, buff);
    }

    s = str->contate;

    //asert
    if(strcmp(str_result, s))
        TEST_FAIL();
}

void read_from_std_input_Tests()
{
    RUN_TEST(read_from_std_input_simple_test1);
}
