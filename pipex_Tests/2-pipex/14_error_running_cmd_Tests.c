#include "../Tests.h"

void error_running_cmd_simple_test1()
{    
    //arrange
    // void error_running_cmd(char *cmd_path, char **args)
    char *cmd_path = ft_strdup_without_save_mem("this is a test");
    char **args = ft_calloc_without_save(4, sizeof(char *));
    args[0] = ft_strdup_without_save_mem("ls");
    args[1] = ft_strdup_without_save_mem("ls");
    args[2] = ft_strdup_without_save_mem("ls");
    args[3] = 0;
    is_pass_exit(0);

    //act
    error_running_cmd(cmd_path, args);

    //asert
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));
}

void error_running_cmd_Tests()
{
    RUN_TEST(error_running_cmd_simple_test1);
}
