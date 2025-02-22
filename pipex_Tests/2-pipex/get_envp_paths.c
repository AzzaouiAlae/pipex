#include "../Tests.h"
#include <string.h>

void get_envp_paths_simple_test1()
{
    //arrange
    char **result;
    char *input[] = {"", "", "Hello", "PATH=/home/aazzaoui/.local/bin:/home/aazzaoui/bin:/usr/share/Modules/bin:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/home/aazzaoui/.dotnet/tools", 0};
    char *EXP[] = {"/home/aazzaoui/.local/bin", "/home/aazzaoui/bin", "/usr/share/Modules/bin", "/usr/local/bin", "/usr/local/sbin", "/usr/bin", "/usr/sbin", "/home/aazzaoui/.dotnet/tools", 0};
    //act
    result = get_envp_paths(input);

    //asert
    if(!result)
            TEST_FAIL();
    for(int i = 0; 8 > i; i++)
    {
        if(result[i] != 0)
        {
            TEST_ASSERT_EQUAL_INT64(strlen(EXP[i]), strlen(result[i]));
            TEST_ASSERT_EQUAL_CHAR_ARRAY(EXP[i], result[i], strlen(EXP[i]));
        }
        else
            TEST_ASSERT_EQUAL_INT64(EXP[i], result[i]);
    }
    
}
void get_envp_paths_simple_test2()
{
    //arrange
    char **result;
    char *input[] = {"", "", "Hello", "", 0};
    is_pass_exit(0);

    //act
    result = get_envp_paths(input);

    //asert
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void get_envp_paths_tests()
{
    RUN_TEST(get_envp_paths_simple_test1);
    RUN_TEST(get_envp_paths_simple_test2);
}