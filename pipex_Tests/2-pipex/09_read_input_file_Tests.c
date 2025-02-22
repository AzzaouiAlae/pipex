#include "../Tests.h"
#include <string.h>

void read_input_file_simple_test1()
{
    //arrange
    all_pipes(null, NULL);
    t_pipe *p;
    t_cs_list *str = cs_list_new(sizeof(char));
    char *str_result = "this is a file5555";
    char buff[10];
    int n = 10;
    char *s;
    is_pass_exit(0);

    //act
    read_input_file("file333.txt");
    p = current_pipe();
    while(n == 10)
    {
        n = read(p->fd_read, buff, 10);
        cs_list_add_range(str, n, buff);
    }

    //asert
    TEST_ASSERT_EQUAL_INT64(0, is_pass_exit(-10));
    s = str->contate;
    if(!s)
        TEST_FAIL();       
    if(strcmp(str_result, s))
        TEST_FAIL();
}

void read_input_file_simple_test2()
{
    //arrange    
    char *fileName = "file33.txt";
    char *exp = "this is a file5555";

    //act
    char *result = read_file(fileName);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void read_input_file_Tests()
{
    RUN_TEST(read_input_file_simple_test1);
    RUN_TEST(read_input_file_simple_test2);
}
