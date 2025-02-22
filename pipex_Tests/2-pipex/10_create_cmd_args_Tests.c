#include "../Tests.h"

void create_cmd_args_simple_test1()
{
    //arrange
    //char *paths = "PATH=/home/aazzaoui/.local/bin:/home/aazzaoui/bin:/usr/share/Modules/bin:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/home/aazzaoui/.dotnet/tools";
    //char *e_paths[] = {"/home/aazzaoui/.local/bin", "/home/aazzaoui/bin", "/usr/share/Modules/bin", "/usr/local/bin", "/usr/local/sbin", "/usr/bin", "/usr/sbin", "/home/aazzaoui/.dotnet/tools"};
    //char **r_paths;
    char *cmds = "ls -l -t";
    char *exp[] = {"ls", "-l", "-t", 0};
    char **r_cmds;

    //act
    r_cmds = create_cmd_args(cmds);

    //asert  
    if(!r_cmds)
            TEST_FAIL();
    for(int i = 0; exp[i]; i++)  
    {
        if(!r_cmds[i])
            TEST_FAIL();
        TEST_ASSERT_CHAR_ARRAY_WITHIN(0, exp[i], r_cmds[i], ft_strlen(exp[i]) + 1);
    }        
}

void create_cmd_args_Tests()
{
    RUN_TEST(create_cmd_args_simple_test1);
}